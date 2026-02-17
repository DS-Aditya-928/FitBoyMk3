#include <appBasic.h>
#include <notificationViewer.h>
#include <utils.h>
#include <styles.h>

//d2fa52f9-4c5d-4a05-a010-c26a1b99f5e6
#define NOTIFICATION_SERVICE_UUID_VAL BT_UUID_128_ENCODE(0xd2fa52f9, 0x4c5d, 0x4a05, 0xa010, 0xc26a1b99f5e6)
static struct bt_uuid_128 notification_service_uuid = BT_UUID_INIT_128(NOTIFICATION_SERVICE_UUID_VAL);

//05590c96-12bb-11ee-be56-0242ac120002
#define NOTIF_CHAR_UUID_VAL BT_UUID_128_ENCODE(0x05590c96, 0x12bb, 0x11ee, 0xbe56, 0x0242ac120002)
static struct bt_uuid_128 notif_char_uuid = BT_UUID_INIT_128(NOTIF_CHAR_UUID_VAL);

//19e04166-12bb-11ee-be56-0242ac120002
#define NOTIF_PHDEL_CHAR_UUID_VAL BT_UUID_128_ENCODE(0x019e04166, 0x12bb, 0x11ee, 0xbe56, 0x0242ac120002)
static struct bt_uuid_128 notif_phdel_char_uuid = BT_UUID_INIT_128(NOTIF_PHDEL_CHAR_UUID_VAL);

//c533a7ba-272e-11ee-be56-0242ac120002
#define NOTIF_FBDEL_CHAR_UUID_VAL BT_UUID_128_ENCODE(0x0c533a7ba, 0x272e, 0x11ee, 0xbe56, 0x0242ac120002)
static struct bt_uuid_128 notif_fbdel_char_uuid = BT_UUID_INIT_128(NOTIF_FBDEL_CHAR_UUID_VAL);

lv_obj_t* list;
static lv_obj_t* screen;
static lv_group_t* g;

struct NotificationArgs
{
    lv_obj_t* parent;
    char* appName;
    char* title;
    char* subTitle;
    char* key;
    char* text;
    char* id;
    struct k_work_delayable task;
};


static void cardDelCB(lv_event_t* e);
static void addNotification(struct k_work* work)
{
    printf("Adding notification to viewer\n");

    struct NotificationArgs* notif = CONTAINER_OF(work, struct NotificationArgs, task.work);

    k_mutex_lock(&lvglMutex, K_FOREVER); 
    lv_obj_t* card = NULL;
    uint32_t numObj = lv_group_get_obj_count(g);
    for(int i = 0; i < numObj; i++)
    {
        lv_obj_t* p = lv_group_get_obj_by_index(g, i);
        if(p)
        {
            if(strcmp(lv_obj_get_user_data(p), notif->id) == 0)
            {
                printk("Updating existing\n");
                card = p;
                lv_obj_clean(card);
                break;
            }
        }
    }
    
    //Card
    if(card == NULL)
    {
        card = lv_obj_create(notif->parent);
        lv_obj_set_user_data(card, (void*)notif->id);

        lv_obj_set_width(card, 128);
        lv_obj_set_height(card, LV_SIZE_CONTENT);
        lv_obj_set_flex_flow(card, LV_FLEX_FLOW_ROW);
        lv_obj_set_scrollbar_mode(card, LV_SCROLLBAR_MODE_OFF);

        lv_obj_add_style(card, &tight, LV_STATE_DEFAULT);
        lv_obj_add_style(card, &tight_aoCard, LV_STATE_DEFAULT);

        lv_obj_add_flag(card, LV_OBJ_FLAG_CLICKABLE);
        lv_obj_add_flag(card, LV_OBJ_FLAG_SCROLL_ON_FOCUS);
        lv_obj_clear_flag(card, LV_OBJ_FLAG_SCROLLABLE);
    
        lv_obj_add_event_cb(card, cardDelCB, LV_EVENT_CLICKED, NULL);
    }
    
    //Text container
    lv_obj_t* textContainer = lv_obj_create(card);
    lv_obj_set_width(textContainer, lv_pct(100));
    lv_obj_set_height(textContainer, LV_SIZE_CONTENT);
    lv_obj_set_flex_flow(textContainer, LV_FLEX_FLOW_COLUMN);
    lv_obj_set_scrollbar_mode(textContainer, LV_SCROLLBAR_MODE_OFF);

    lv_obj_add_style(textContainer, &tight, LV_STATE_DEFAULT);

    lv_obj_add_flag(textContainer, LV_OBJ_FLAG_CLICKABLE); 
    lv_obj_clear_flag(textContainer, LV_OBJ_FLAG_CLICK_FOCUSABLE);
    
    //Header
    lv_obj_t* headerRow = lv_obj_create(textContainer);
    lv_obj_set_size(headerRow, lv_pct(100), LV_SIZE_CONTENT);
    lv_obj_set_flex_flow(headerRow, LV_FLEX_FLOW_ROW);

    lv_obj_add_style(headerRow, &tight, LV_STATE_DEFAULT);
    lv_obj_add_style(headerRow, &tight_aoHeader, LV_STATE_DEFAULT);

    //Title (appname)
    lv_obj_t* titleLabel = lv_label_create(headerRow);
    lv_obj_set_width(titleLabel, LV_SIZE_CONTENT); 
    lv_label_set_long_mode(titleLabel, LV_LABEL_LONG_SCROLL_CIRCULAR);

    lv_obj_add_style(titleLabel, &tight, LV_STATE_DEFAULT);
    lv_obj_add_style(titleLabel, &tight_aoTitle, LV_STATE_DEFAULT);
    
    lv_label_set_text(titleLabel, notif->appName);
    
    //Separator
    lv_obj_t* sepLabel = lv_label_create(headerRow);
    lv_label_set_text(sepLabel, "|");

    //Subtitle (title)
    lv_obj_t* subtitleLabel = lv_label_create(headerRow);
    lv_obj_set_flex_grow(subtitleLabel, 1);
    lv_label_set_long_mode(subtitleLabel, LV_LABEL_LONG_SCROLL_CIRCULAR);

    lv_obj_add_style(subtitleLabel, &tight, LV_STATE_DEFAULT);
    
    lv_label_set_text(subtitleLabel, notif->title);
    
    //Message
    lv_obj_t* msgLabel = lv_label_create(textContainer);
    lv_obj_set_width(msgLabel, lv_pct(100)); 
    lv_obj_set_height(msgLabel, LV_SIZE_CONTENT);
    lv_label_set_long_mode(msgLabel, LV_LABEL_LONG_WRAP);

    lv_obj_add_style(msgLabel, &tight, LV_STATE_DEFAULT);
    lv_obj_add_style(msgLabel, &tight_aoMsgLabel, LV_STATE_DEFAULT);

    lv_label_set_text(msgLabel, notif->text);
    
    //END NOTIF CREATION
    lv_group_add_obj(g, card);

    k_free(notif->appName);
    k_free(notif->title);
    k_free(notif->subTitle);
    k_free(notif->key);
    k_free(notif->text);
    //k_free(notif->id);
    k_free(notif);

    k_mutex_unlock(&lvglMutex);
    print_heap_stats();
    printf("Notification added to viewer\n");
}

static struct BTDePacket phoneNotifDel = {0};
static ssize_t phoneNotifDelCB(struct bt_conn *conn, const struct bt_gatt_attr *attr,
			     const void *buf, uint16_t len, uint16_t offset,
			     uint8_t flags)
{
    if(processPackets(buf, len, &phoneNotifDel) == DONE)
    {
        printf("Full ID %s\n", phoneNotifDel.finalStr);

        uint32_t numObj = lv_group_get_obj_count(g);
        for(int i = 0; i < numObj; i++)
        {
            lv_obj_t* p = lv_group_get_obj_by_index(g, i);
            if(p)
            {
                if(strcmp((char*)lv_obj_get_user_data(p), phoneNotifDel.finalStr) == 0)
                {
                    k_free(lv_obj_get_user_data(p));
                    lv_obj_set_user_data(p, NULL);
                    lv_obj_del_async(p);
                }
            }

            else
            {
                printf("NULLID\n");
            }
        }

        k_free(phoneNotifDel.finalStr);
    }

    return len;
}

static struct BTDePacket incomingNotif = {0};
static ssize_t notificationSet(struct bt_conn *conn, const struct bt_gatt_attr *attr,
			     const void *buf, uint16_t len, uint16_t offset,
			     uint8_t flags)
{

    if(processPackets(buf, len, &incomingNotif) == DONE)
    {
        printf("Full notification %s\n", incomingNotif.finalStr);
        
        char* appName  = getPart(incomingNotif.finalStr, "<0>", "<1>");
        char* title    = getPart(incomingNotif.finalStr, "<1>", "<2>");
        char* subTitle = getPart(incomingNotif.finalStr, "<2>", "<3>");
        char* key      = getPart(incomingNotif.finalStr, "<3>", "<4>");
        char* text     = getPart(incomingNotif.finalStr, "<4>", "<5>");
        char* id       = getPart(incomingNotif.finalStr, "<5>", NULL);
        k_free(incomingNotif.finalStr);

        trim(appName);
        trim(title);
        trim(subTitle);
        trim(text);

        printk("App Name: %s\nTitle: %s\nSubtitle: %s\nKey: %s\nText: %s\nID: %s\n", appName, title, subTitle, key, text, id);
        
        struct NotificationArgs* notif = (struct NotificationArgs*)k_calloc(1, sizeof(struct NotificationArgs));
        notif->parent = list;
        notif->appName = appName;
        notif->title = title;
        notif->subTitle = subTitle;
        notif->key = key;
        notif->text = text;
        notif->id = id;
        
        k_work_init((struct k_work*)&notif->task, addNotification);
        k_work_schedule(&notif->task, K_MSEC(100));
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

char idArr[256] = {0};
BT_GATT_SERVICE_DEFINE(notification_service,
    BT_GATT_PRIMARY_SERVICE(&notification_service_uuid),
    BT_GATT_CHARACTERISTIC(&notif_char_uuid.uuid,
                           BT_GATT_CHRC_READ | BT_GATT_CHRC_WRITE,
                           BT_GATT_PERM_READ | BT_GATT_PERM_WRITE, 
                           0, notificationSet, 
                           incomingNotif.inPacket),
    BT_GATT_CHARACTERISTIC(&notif_phdel_char_uuid.uuid,
                           BT_GATT_CHRC_READ | BT_GATT_CHRC_WRITE,
                           BT_GATT_PERM_READ | BT_GATT_PERM_WRITE, 
                           0, phoneNotifDelCB, 
                           phoneNotifDel.inPacket),
    BT_GATT_CHARACTERISTIC(&notif_fbdel_char_uuid.uuid,
                           BT_GATT_CHRC_READ | BT_GATT_CHRC_WRITE | BT_GATT_CHRC_NOTIFY,
                           BT_GATT_PERM_READ | BT_GATT_PERM_WRITE, 
                           cRead, cWrite, 
                           idArr),
    BT_GATT_CCC(cccCFGChange, BT_GATT_PERM_READ | BT_GATT_PERM_WRITE)
);

#define PACKET_SIZE 60

static void cardDelCB(lv_event_t* e) 
{
    lv_obj_t* card = lv_event_get_target(e);
    char* toSend = lv_obj_get_user_data(card);
    size_t lenToSend = strlen(toSend) + 1;
    size_t sent = 0;
    while(sent < lenToSend)
    {
        size_t packetLen = MIN(lenToSend - sent, PACKET_SIZE);
        int err = bt_gatt_notify(NULL, &notification_service.attrs[6], toSend + sent, packetLen);
        printk("Sending from index %d, code = %d\n", sent, err);
        sent += packetLen;
    }
    
    k_free(lv_obj_get_user_data(card));
    lv_obj_set_user_data(card, NULL);
    lv_obj_del_async(card);
}

void NotificationViewer(void)
{
    screen = lv_obj_create(0);
    g = lv_group_create();
    list = lv_obj_create(screen);
    printk("Notification Viewer Loaded\n");
    
    lv_obj_set_size(list, 128, 64);
    lv_obj_set_pos(list, 0, 0);
    lv_obj_set_flex_flow(list, LV_FLEX_FLOW_COLUMN);
    lv_obj_set_scroll_dir(list, LV_DIR_VER);
    lv_obj_set_scroll_snap_y(list, LV_SCROLL_SNAP_START);

    lv_obj_add_style(list, &listMain, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_add_style(list, &listScrollbar, LV_PART_SCROLLBAR | LV_STATE_DEFAULT);

    lv_obj_t* card = lv_obj_create(list);
    lv_obj_add_style(card, &tight, LV_STATE_DEFAULT);
    lv_obj_set_width(card, lv_pct(100));
    lv_obj_set_height(card, LV_SIZE_CONTENT);
    lv_obj_set_flex_flow(card, LV_FLEX_FLOW_ROW);
    lv_obj_add_flag(card, LV_OBJ_FLAG_SCROLL_ON_FOCUS);
    lv_obj_clear_flag(card, LV_OBJ_FLAG_CLICKABLE);
    lv_obj_clear_flag(card, LV_OBJ_FLAG_SCROLLABLE);

    lv_obj_t* titleLabel = lv_label_create(card);
    lv_obj_add_style(titleLabel, &tight, LV_STATE_DEFAULT);
    lv_obj_add_style(titleLabel, &tightTitle, LV_STATE_DEFAULT);
    lv_label_set_text(titleLabel, "Notifications");

    lv_group_add_obj(g, card);
    k_thread_suspend(k_current_get());
    /*
    lv_obj_t* card1 = addNotification(list, "Test App", "Header", "This is a test notification to demonstrate the notification viewer app. It should scroll if it exceeds the width of the screen.", "B");
    lv_obj_t* card2 = addNotification(list, "Second Notification", "Random garbage idk", "This is another notification to show multiple notifications in the viewer. The viewer should be able to handle multiple notifications and display them properly.", "A");
    
    lv_group_add_obj(g, card1);
    lv_group_add_obj(g, card2);
    */
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

K_THREAD_DEFINE(notificationViewer_thread, 16384, NotificationViewer, NULL, NULL, NULL, 7, 0, 0);
App notificationViewerApp = 
{
    .threadId = notificationViewer_thread,
    .screen = &screen,
    .inputGroup = &g,
    .name = "Notification Viewer"
};