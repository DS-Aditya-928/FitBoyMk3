#include <zephyr/bluetooth/bluetooth.h>
#include <zephyr/posix/time.h>
#include <time.h>

//1f55d926-12bb-11ee-be56-0242ac120007
#define MAINMENU_SERVICE_UUID_VAL BT_UUID_128_ENCODE(0x1f55d926, 0x12bb, 0x11ee, 0xbe56, 0x0242ac120007)
static struct bt_uuid_128 mainmenu_service_uuid = BT_UUID_INIT_128(MAINMENU_SERVICE_UUID_VAL);

//93c37a10-1f37-11ee-be56-0242ac120002
#define TIME_CHAR_UUID_VAL BT_UUID_128_ENCODE(0x93c37a10, 0x1f37, 0x11ee, 0xbe56, 0x0242ac120002)
static struct bt_uuid_128 time_uuid = BT_UUID_INIT_128(TIME_CHAR_UUID_VAL);

uint64_t unixTime = 0;

static ssize_t timeSet(struct bt_conn *conn, const struct bt_gatt_attr *attr,
			     const void *buf, uint16_t len, uint16_t offset,
			     uint8_t flags)
{
    if (len != sizeof(uint64_t)) {
        printk("Invalid time length\n");
        return -EINVAL;
    }

    unixTime = *(uint64_t *)buf;
    printk("Received time: %llu\n", unixTime);
    struct timespec ts;
    ts.tv_sec = unixTime;
    ts.tv_nsec = 0;

    if (clock_settime(CLOCK_REALTIME, &ts) != 0) {
        printk("Failed to set system time\n");
        return -EIO;
    }
    return len;
}

BT_GATT_SERVICE_DEFINE(mainmenu_service,
    BT_GATT_PRIMARY_SERVICE(&mainmenu_service_uuid),
    BT_GATT_CHARACTERISTIC(&time_uuid.uuid,
                           BT_GATT_CHRC_READ | BT_GATT_CHRC_WRITE,
                           BT_GATT_PERM_READ | BT_GATT_PERM_WRITE, 
                           0, timeSet, 
                           &unixTime),
    // Client Characteristic Configuration
    //BT_GATT_CCC(my_ccc_cfg_changed, BT_GATT_PERM_READ | BT_GATT_PERM_WRITE),
);

K_SEM_DEFINE(timeUpdate_sem, 0, 1);

void timeUpdate()
{
    struct timespec ts;
    if (clock_gettime(CLOCK_REALTIME, &ts) != 0) {
        printk("Failed to get system time\n");
        return;
    }

    printk("Current time: %lld\n", (long long)ts.tv_sec);

    unixTime = ts.tv_sec;
    k_sem_give(&timeUpdate_sem);
}

void MainMenu(void)
{
    printk("Main Menu Loaded\n");
    struct k_timer timer;
    k_timer_init(&timer, timeUpdate, NULL);
    k_timer_start(&timer, K_SECONDS(1), K_SECONDS(1));

    lv_style_t style;
    lv_style_init(&style);
        
    lv_style_set_text_font(&style, &TallerFont);
    lv_obj_t *time_label = lv_label_create(lv_scr_act());
    lv_obj_add_style(time_label, &style, 0); 
        
    while(1)
    {
        //render
        
        struct timespec ts;
        clock_gettime(CLOCK_REALTIME, &ts);

        struct tm time_info;
        char buffer[6];
        gmtime_r(&(ts.tv_sec), &time_info);

        strftime(buffer, sizeof(buffer), "%H:%M", &time_info);
        lv_label_set_text(time_label, buffer);
        
        lv_task_handler();
        //wait
        k_sem_take(&timeUpdate_sem, K_FOREVER);
    }
}

//K_THREAD_DEFINE(mainMenu_thread, 16384, MainMenu, NULL, NULL, NULL, 7, 0, 100000);