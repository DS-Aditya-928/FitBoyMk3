#include <appBasic.h>
#include <notificationViewer.h>
#include <utils.h>
#include <buttons.h>
#include <../notifications/styles.h>


//019c9698-ccae-7bd0-9976-3017ee420aba
#define MUSIC_SERVICE_UUID_VAL BT_UUID_128_ENCODE(0x019c9698, 0xccae, 0x7bd0, 0x9976, 0x3017ee420aba)
static struct bt_uuid_128 music_service_uuid = BT_UUID_INIT_128(MUSIC_SERVICE_UUID_VAL);

//6ddb28be-a927-11ee-a506-0242ac120002
#define MUSIC_CONTROL_CHAR_UUID_VAL BT_UUID_128_ENCODE(0x06ddb28be, 0xa927, 0x11ee, 0xa506, 0x0242ac120002)
static struct bt_uuid_128 music_control_char_uuid = BT_UUID_INIT_128(MUSIC_CONTROL_CHAR_UUID_VAL);

//5df4d2b0-a927-11ee-a506-0242ac120002
#define MUSIC_METADATA_CHAR_UUID_VAL BT_UUID_128_ENCODE(0x05df4d2b0, 0xa927, 0x11ee, 0xa506, 0x0242ac120002)
static struct bt_uuid_128 music_metadata_char_uuid = BT_UUID_INIT_128(MUSIC_METADATA_CHAR_UUID_VAL);


static struct BTDePacket musicMetadata = {0};
static ssize_t notificationSet(struct bt_conn *conn, const struct bt_gatt_attr *attr,
			     const void *buf, uint16_t len, uint16_t offset,
			     uint8_t flags)
{

    if(processPackets(buf, len, &musicMetadata) == DONE)
    {
        printf("Full music metadata %s\n", musicMetadata.finalStr);
    }
    return len;
}


static ssize_t cWrite(struct bt_conn *conn, const struct bt_gatt_attr *attr,
			     const void *buf, uint16_t len, uint16_t offset,
			     uint8_t flags)
{
    printk("Characteristic written to\n");
    return len;
}


static ssize_t cRead(struct bt_conn *conn, const struct bt_gatt_attr *attr,
			     const void *buf, uint16_t len, uint16_t offset)
{
    printk("Characteristic read from\n");
    return len;
}


static void cccCFGChange(const struct bt_gatt_attr *attr, uint16_t value)
{
    printk("Charactertic descriptor written to\n");
	printk("Notifications %s\n", (value == BT_GATT_CCC_NOTIFY) ? "enabled" : "disabled");
}

char buttonSend[64] = {0}; //could shrink lowkey we only send like 1 char at a time
BT_GATT_SERVICE_DEFINE(music_service,
    BT_GATT_PRIMARY_SERVICE(&music_service_uuid),
    BT_GATT_CHARACTERISTIC(&music_metadata_char_uuid.uuid,
                           BT_GATT_CHRC_READ | BT_GATT_CHRC_WRITE,
                           BT_GATT_PERM_READ | BT_GATT_PERM_WRITE, 
                           0, notificationSet, 
                           musicMetadata.inPacket),
    BT_GATT_CHARACTERISTIC(&music_control_char_uuid.uuid,
                           BT_GATT_CHRC_READ | BT_GATT_CHRC_WRITE | BT_GATT_CHRC_NOTIFY,
                           BT_GATT_PERM_READ | BT_GATT_PERM_WRITE, 
                           cRead, cWrite, 
                           buttonSend),
    BT_GATT_CCC(cccCFGChange, BT_GATT_PERM_READ | BT_GATT_PERM_WRITE)
);

static lv_obj_t* screen;
static lv_group_t* g;

static void testFunc(lv_event_t * e) 
{
    lv_event_code_t code = lv_event_get_code(e);
    lv_obj_t * screen = lv_event_get_target(e);
    printf("Event code: %d\n", code);
    printf("Key: %d\n", lv_indev_get_key(indev));
    printf("Scroll dir: %d\n", lv_event_get_rotary_diff(e));
    if(code == LV_EVENT_KEY) 
    {
        uint32_t key = lv_indev_get_key(lv_indev_get_act());

        if(key == LV_KEY_NEXT) {
            // Logic for Encoder "Down" or "Right"
            printf("Encoder turned UP/Right\n");
        } 
        else if(key == LV_KEY_PREV) {
            // Logic for Encoder "Up" or "Left"
            printf("Encoder turned DOWN/Left\n");
        }
        else if(key == LV_KEY_ENTER) {
            // Logic for Encoder Click
            printf("Encoder Pressed\n");
        }
    }
}


void MusicControl(void)
{
    screen = lv_obj_create(0);
    g = lv_group_create();
    printk("Music Control Loaded\n");
    
    lv_group_add_obj(g, screen);
    lv_group_focus_freeze(g, true);
    lv_group_set_editing(g, true);

    lv_obj_add_event_cb(screen, testFunc, LV_EVENT_ALL, NULL);
    lv_obj_add_flag(screen, LV_OBJ_FLAG_CLICKABLE);
    //lv_group_focus_obj(screen);
    k_thread_suspend(k_current_get());
    
    while(1)
    {
        //render
        //printf("Active object: %p\n", lv_group_get_focused(g));
        //printf("All objects: %p, %p, %p\n", card, card1, card2);
        k_mutex_lock(&lvglMutex, K_FOREVER);
        lv_task_handler();
        k_mutex_unlock(&lvglMutex);
        k_sleep(K_MSEC(5));
    }
}

K_THREAD_DEFINE(musicControl_thread, 16384, MusicControl, NULL, NULL, NULL, 7, 0, 0);
App musicControlApp = 
{
    .threadId = musicControl_thread,
    .screen = &screen,
    .inputGroup = &g,
    .name = "Music Control"
};