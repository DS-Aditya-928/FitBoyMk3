#include <ctype.h>
#include <time.h>

#include <appBasic.h>

#include <notificationViewer.h>
#include <mainMenu.h>

//1f55d926-12bb-11ee-be56-0242ac120007
#define MAINMENU_SERVICE_UUID_VAL BT_UUID_128_ENCODE(0x1f55d926, 0x12bb, 0x11ee, 0xbe56, 0x0242ac120007)
static struct bt_uuid_128 mainmenu_service_uuid = BT_UUID_INIT_128(MAINMENU_SERVICE_UUID_VAL);

//93c37a10-1f37-11ee-be56-0242ac120002
#define TIME_CHAR_UUID_VAL BT_UUID_128_ENCODE(0x93c37a10, 0x1f37, 0x11ee, 0xbe56, 0x0242ac120002)
static struct bt_uuid_128 time_uuid = BT_UUID_INIT_128(TIME_CHAR_UUID_VAL);

uint64_t unixTime = 0;

//LV_FONT_DECLARE(TallerFont);
//LV_FONT_DECLARE(TallerFont_small);
LV_FONT_DECLARE(Mostane_32);
LV_FONT_DECLARE(Mostane_64);

static ssize_t timeSet(struct bt_conn *conn, const struct bt_gatt_attr *attr,
			     const void *buf, uint16_t len, uint16_t offset,
			     uint8_t flags)
{
    if (len != sizeof(uint64_t)) 
    {
        printk("Invalid time length\n");
        return -EINVAL;
    }

    unixTime = *(uint64_t *)buf;
    printk("Received time: %llu\n", unixTime);
    struct timespec ts;
    ts.tv_sec = unixTime;
    ts.tv_nsec = 0;

    if (clock_settime(CLOCK_REALTIME, &ts) != 0)
    {
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

    //printk("Current time: %lld\n", (long long)ts.tv_sec);

    unixTime = ts.tv_sec;
    k_sem_give(&timeUpdate_sem);
}

lv_obj_t* screen1;

static const lv_style_const_prop_t style_props[] = {
    LV_STYLE_CONST_TEXT_FONT(&Mostane_64),
    LV_STYLE_CONST_PROPS_END
};
LV_STYLE_CONST_INIT(style1, style_props);

static lv_style_const_prop_t style_props2[] = {
    LV_STYLE_CONST_TEXT_FONT(&Mostane_32),
    LV_STYLE_CONST_PROPS_END
};
LV_STYLE_CONST_INIT(style2, style_props2);

LV_IMAGE_DECLARE(Bell);

void MainMenu(void)
{
    screen1 = lv_obj_create(0);
    printk("Main Menu Loaded\n");

    lv_obj_t* timeLabel = lv_label_create(screen1);
    //lv_obj_t* minuteLabel = lv_label_create(screen1);
    lv_obj_t* secondLabel = lv_label_create(screen1);
    lv_obj_t* dayLabel = lv_label_create(screen1);
    lv_obj_t* notifLabel = lv_label_create(screen1);
    //lv_obj_t* bellLabel = lv_label_create(screen1);
    lv_obj_t* bellBmp = lv_image_create(screen1);

    lv_image_set_src(bellBmp, &Bell);
    lv_label_set_text(notifLabel, "00");

    lv_obj_set_pos(timeLabel, 0, 0);
    //lv_obj_set_pos(minuteLabel, 39, 0);
    lv_obj_set_pos(secondLabel, 82, 33);
    lv_obj_set_pos(dayLabel, 82, 0);
    lv_obj_set_align(bellBmp, LV_ALIGN_TOP_RIGHT);
    lv_obj_set_align(notifLabel, LV_ALIGN_BOTTOM_RIGHT);
    //lv_obj_set_align(bellLabel, LV_ALIGN_TOP_RIGHT);

    lv_obj_add_style(secondLabel, &style2, 0);
    lv_obj_add_style(timeLabel, &style1, 0); 
    //lv_obj_add_style(minuteLabel, &style, 0);
    lv_obj_add_style(dayLabel, &style2, 0);
    lv_obj_add_style(notifLabel, &style2, 0);
    //lv_obj_add_style(bellLabel, &style2, 0);
        
    lv_obj_set_size(secondLabel, 18, 31);
    lv_obj_set_size(notifLabel, 18, 31);

    char bufferTime[6];
    //char bufferMin[3];
    char buffer2[3];
    char buffer3[4];
    
    //lv_label_set_text(bellLabel, LV_SYMBOL_BELL);

    k_thread_suspend(k_current_get());
    struct k_timer timer;
    k_timer_init(&timer, timeUpdate, NULL);
    k_timer_start(&timer, K_SECONDS(1), K_SECONDS(1));
    while(1)
    {
        //render
        k_mutex_lock(&lvglMutex, K_FOREVER);
        struct timespec ts;
        clock_gettime(CLOCK_REALTIME, &ts);

        struct tm time_info;
        gmtime_r(&(ts.tv_sec), &time_info);

        strftime(bufferTime, sizeof(bufferTime), "%H:%M", &time_info);
        //strftime(bufferMin, sizeof(bufferMin), "%M", &time_info);
        strftime(buffer2, sizeof(buffer2), "%S", &time_info);
        strftime(buffer3, sizeof(buffer3), "%a", &time_info);

        if(bufferTime[0] == '1')
        {
            lv_obj_set_x(timeLabel, 5);
        }

        else
        {
            lv_obj_set_x(timeLabel, 0);
        }

        if(buffer2[0] == '1')
        {
            lv_obj_set_x(secondLabel, 85);
        }

        else
        {
            lv_obj_set_x(secondLabel, 82);
        }

        for(int i = 0; i < 4; i++)
        {
            buffer3[i] = toupper(buffer3[i]);
        }

        lv_label_set_text_static(timeLabel, bufferTime);
        lv_label_set_text_static(secondLabel, buffer2);
        lv_label_set_text_static(dayLabel, buffer3);
        uint8_t notCount = getNotifCount();
        lv_label_set_text_fmt(notifLabel, "%02d", (int)notCount);

        if(notCount)
        {
            lv_obj_remove_flag(bellBmp, LV_OBJ_FLAG_HIDDEN);
            lv_obj_remove_flag(notifLabel, LV_OBJ_FLAG_HIDDEN);
        }

        else
        {
            lv_obj_add_flag(bellBmp, LV_OBJ_FLAG_HIDDEN);
            lv_obj_add_flag(notifLabel, LV_OBJ_FLAG_HIDDEN);
        }

        lv_task_handler();
        k_mutex_unlock(&lvglMutex);
        //wait
        k_sem_take(&timeUpdate_sem, K_FOREVER);
    }
}

K_THREAD_DEFINE(mainMenu_thread, 16384, MainMenu, NULL, NULL, NULL, 7, 0, 0);
App mainMenuApp = 
{
    .threadId = mainMenu_thread,
    .screen = &screen1,
    .name = "MainMenu"
};