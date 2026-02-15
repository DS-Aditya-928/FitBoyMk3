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

char notificationText[256] = {0};
char* preProcText = 0;
uint16_t preProcTextIndex = 0;
uint16_t preProcTextLen = 0;
static bool incomingNotification = false;
lv_obj_t* list;
static lv_obj_t* screen;
static lv_group_t* g;

//static struct k_work_delayable task;

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

//static lv_obj_t* addNotification(lv_obj_t* parent, const char* appName, const char* title, const char* msg, const char* id);
static void addNotification(struct k_work* work);
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
        print_heap_stats();
        preProcText = (char*)k_calloc((*(int16_t*)buf) + 1, sizeof(char));
        if(preProcText == NULL)
        {
            printk("Failed to allocate memory for incoming notification\n");
            return -ENOMEM;
        }

        printk("Allocated %d bytes for incoming notification\n", (*(int16_t*)buf) + 1);
        preProcTextLen = *(int16_t*)(buf);
        incomingNotification = true;
        preProcTextIndex += len - 2;
        memcpy(preProcText, (char*)buf + 2, len - 2);
    }

    else
    {
        memcpy(preProcText + preProcTextIndex, buf, len);
        preProcTextIndex += len;
    }

    printk("Received notification chunk: %d bytes, total received: %d/%d\n", len, preProcTextIndex, preProcTextLen);

    if(preProcTextIndex >= preProcTextLen)
    {
        printk("Full notification received %s bytes, length: %d\n", preProcText, preProcTextLen);
        print_heap_stats();

        char* appName  = getPart(preProcText, "<0>", "<1>");
        char* title    = getPart(preProcText, "<1>", "<2>");
        char* subTitle = getPart(preProcText, "<2>", "<3>");
        char* key      = getPart(preProcText, "<3>", "<4>");
        char* text     = getPart(preProcText, "<4>", "<5>");
        char* id       = getPart(preProcText, "<5>", NULL);

        printk("App Name: %s\nTitle: %s\nSubtitle: %s\nKey: %s\nText: %s\nID: %s\n", appName, title, subTitle, key, text, id);
        notificationText[preProcTextLen] = 0;
        k_free(preProcText);

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

        //lv_obj_t* card = addNotification(list, appName, title, text, id);
        preProcText = 0;
        preProcTextLen = 0;
        preProcTextIndex = 0;
        incomingNotification = false;
    }

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

static void cardDelCB(lv_event_t* e) 
{
    lv_obj_t* card = lv_event_get_target(e);
    
    lv_obj_del_async(card);
}

static void addNotification(struct k_work* work)
{
    printf("Adding notification to viewer\n");
    print_lvgl_heap_usage();
    print_heap_stats();

    struct NotificationArgs* notif = CONTAINER_OF(work, struct NotificationArgs, task.work);

    k_mutex_lock(&lvglMutex, K_FOREVER); 
    
    //Card
    lv_obj_t* card = lv_obj_create(notif->parent);
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
    k_free(notif->id);
    k_free(notif);

    k_mutex_unlock(&lvglMutex);
    print_heap_stats();
    printf("Notification added to viewer\n");
    //free(notif->id);
    //printf("All objects for %s: %p, %p, %p, %p\n", title, card, text_cont, header_row, lbl_msg);
    //return card;
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