#include <notificationViewer.h>
#include <lvgl.h>
#include <btManager.h>
#include <appManager.h>
#include <buttons.h>


//d2fa52f9-4c5d-4a05-a010-c26a1b99f5e6
#define NOTIFICATION_SERVICE_UUID_VAL BT_UUID_128_ENCODE(0xd2fa52f9, 0x4c5d, 0x4a05, 0xa010, 0xc26a1b99f5e6)
static struct bt_uuid_128 notification_service_uuid = BT_UUID_INIT_128(NOTIFICATION_SERVICE_UUID_VAL);

//05590c96-12bb-11ee-be56-0242ac120002
#define NOTIF_CHAR_UUID_VAL BT_UUID_128_ENCODE(0x05590c96, 0x12bb, 0x11ee, 0xbe56, 0x0242ac120002)
static struct bt_uuid_128 notif_char_uuid = BT_UUID_INIT_128(NOTIF_CHAR_UUID_VAL);

char notificationText[256] = {0};
char* preProcText = 0;
uint16_t preProcTextIndex = 0;
uint16_t preProcTextLen = 0;
static bool incomingNotification = false;

static ssize_t notificationSet(struct bt_conn *conn, const struct bt_gatt_attr *attr,
			     const void *buf, uint16_t len, uint16_t offset,
			     uint8_t flags)
{
    if (len >= sizeof(notificationText) - 1) 
    {
        printk("Invalid notification length\n");
        return -EINVAL;
    }

    if(!incomingNotification)
    {
        preProcText = (char*)malloc(*(int16_t*)buf);
        if(preProcText == NULL)
        {
            printk("Failed to allocate memory for incoming notification\n");
            return -ENOMEM;
        }

        printk("Allocated %d bytes for incoming notification\n", *(int16_t*)buf);
        preProcTextLen = *(int16_t*)buf;
        incomingNotification = true;
        preProcTextIndex += len - 2;
        memcpy(preProcText, buf + 2, len - 2);
    }

    else
    {
        memcpy(preProcText + preProcTextIndex, buf, len);
        preProcTextIndex += len;
    }

    if(preProcTextIndex >= preProcTextLen)
    {
        printk("Full notification received %s bytes, length: %d\n", preProcText, *(int16_t*)preProcTextLen);
        notificationText[preProcTextLen] = 0;
        free(preProcText);
        preProcText = 0;
        preProcTextLen = 0;
        incomingNotification = false;
    }

    //memcpy(notificationText, buf, len);
    //notificationText[len] = 0; 
    printk("Received notification length: %d\n", *(int16_t*)buf);
    printk("Received notification length: %d\n", len);
    printk("Received notification: %s\n", (char*)buf);
    return len;
}

BT_GATT_SERVICE_DEFINE(notification_service,
    BT_GATT_PRIMARY_SERVICE(&notification_service_uuid),
    BT_GATT_CHARACTERISTIC(&notif_char_uuid.uuid,
                           BT_GATT_CHRC_READ | BT_GATT_CHRC_WRITE,
                           BT_GATT_PERM_READ | BT_GATT_PERM_WRITE, 
                           0, notificationSet, 
                           notificationText),
);

LV_FONT_DECLARE(Oswald);

static lv_obj_t* screen1;
static lv_group_t* g;

void NotificationViewer(void)
{
    screen1 = lv_obj_create(0);
    g = lv_group_create();
    k_thread_suspend(k_current_get());
    printk("Notification Viewer Loaded\n");
    
    lv_obj_t* list = lv_list_create(screen1);
    lv_obj_set_size(list, 114, 64);
    lv_obj_set_pos(list, 14, 0);
    lv_obj_set_style_pad_all(list, 0, 0);
    lv_obj_set_style_pad_row(list, 0, 0);
    lv_obj_set_style_border_width(list, 0, 0);
    
    static lv_style_t tight;
    lv_style_init(&tight);
    lv_style_set_pad_ver(&tight, 1);
    lv_style_set_pad_gap(&tight, 5);
    
    lv_style_set_radius(&tight, 0);
    
    lv_style_set_border_width(&tight, 0);
    lv_style_set_outline_width(&tight, 0);
    lv_style_set_border_side(&tight, LV_BORDER_SIDE_NONE);

    lv_style_set_bg_color(&tight, lv_color_white());
    lv_style_set_text_color(&tight, lv_color_black());
    lv_style_set_bg_opa(&tight, LV_OPA_COVER);
    lv_style_set_text_font(&tight, &Oswald);


    static lv_style_t tightSel;
    lv_style_init(&tightSel);
    lv_style_copy(&tightSel, &tight);
    lv_style_set_pad_gap(&tightSel, 15);
    lv_style_set_shadow_width(&tightSel, 0);
    lv_style_set_shadow_spread(&tightSel, 0);

    static lv_style_t tightSelClick;
    lv_style_init(&tightSelClick);
    lv_style_copy(&tightSelClick, &tightSel);
    lv_style_set_bg_color(&tightSelClick, lv_color_black());
    lv_style_set_text_color(&tightSelClick, lv_color_white());

    lv_obj_t* flash = lv_list_add_button(list, NULL, "Flash Firmware");
    lv_obj_t* power = lv_list_add_button(list, NULL, "Power Off");

    lv_obj_add_style(flash, &tight, LV_STATE_DEFAULT);
    lv_obj_add_style(flash, &tightSel, LV_STATE_FOCUSED);
    lv_obj_set_height(flash, LV_SIZE_CONTENT);
    //lv_obj_add_event_cb(flash, flashButtonCB, LV_EVENT_CLICKED, NULL);
    lv_obj_add_style(flash, &tightSelClick, LV_STATE_PRESSED);
    lv_obj_remove_style(flash, NULL, LV_STATE_FOCUS_KEY);

    lv_obj_add_style(power, &tight, LV_STATE_DEFAULT);
    lv_obj_add_style(power, &tightSel, LV_STATE_FOCUSED);
    lv_obj_set_height(power, LV_SIZE_CONTENT);
    //lv_obj_add_event_cb(power, powerButtonCB, LV_EVENT_CLICKED, NULL);
    lv_obj_add_style(power, &tightSelClick, LV_STATE_PRESSED);
    lv_obj_remove_style(power, NULL, LV_STATE_FOCUS_KEY); //just because the default style here isnt what we want.
    
    //lv_obj_add_style(lv_obj_get_child(flash, 0), &monoIcon, 0);
    //lv_obj_add_style(lv_obj_get_child(power, 0), &monoIcon, 0);

    lv_group_add_obj(g, flash);
    lv_group_add_obj(g, power);

    while(1)
    {
        //render
        k_mutex_lock(&lvglMutex, K_FOREVER);
        lv_task_handler();
        k_mutex_unlock(&lvglMutex);
        k_sleep(K_MSEC(5));
    }
}

K_THREAD_DEFINE(notificationViewer_thread, 16384, NotificationViewer, NULL, NULL, NULL, 7, 0, 0);
App notificationViewerApp = 
{
    .threadId = notificationViewer_thread,
    .screen = &screen1,
    .inputGroup = &g,
    .name = "Notification Viewer"
};