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

//019d3745-7fec-7a03-8ab8-4b91c344b29b
#define MUSIC_QUEUE_CHAR_UUID_VAL BT_UUID_128_ENCODE(0x019d3745, 0x7fec, 0x7a03, 0x8ab8, 0x4b91c344b29b)
static struct bt_uuid_128 music_queue_char_uuid = BT_UUID_INIT_128(MUSIC_QUEUE_CHAR_UUID_VAL);

static lv_obj_t* artistLabel;
static lv_obj_t* songLabel;
static lv_obj_t* playPauseLabel;
static lv_obj_t* progressBar;
static lv_obj_t* queueList;

static uint32_t mdTime = 0;
static uint32_t songPos = 0;
static uint32_t songLen = 1;
static bool isPlaying = false;

struct SongArgs
{
    char* artist;
    char* song;
    bool isPlaying;//should rework the way this info is sent
    uint32_t length;
    uint32_t position;

    char* parentStr;
    struct k_work_delayable task;
};

static void updateSongDeets(struct k_work* work)
{
    struct SongArgs* md = CONTAINER_OF(work, struct SongArgs, task.work);

    k_mutex_lock(&lvglMutex, K_FOREVER);

    mdTime = k_uptime_seconds();
    songPos = md->position;
    songLen = MAX(md->length, 1);
    isPlaying = md->isPlaying;
    
    lv_label_set_text(artistLabel, md->artist);
    lv_label_set_text(songLabel, md->song);
    lv_label_set_text(playPauseLabel, (isPlaying?LV_SYMBOL_PAUSE:LV_SYMBOL_PLAY));
    lv_bar_set_value(progressBar, (100 * songPos)/songLen, LV_ANIM_ON); // technically unnecessary but should stop anim on mode switch

    //printk("%d, %d", songPos, songLen);
    k_mutex_unlock(&lvglMutex);

    k_free(md->parentStr);
    k_free(md);
}

struct k_work_delayable csdTask;
static void clearSongDeets(struct k_work* work)
{
    k_mutex_lock(&lvglMutex, K_FOREVER);
    
    lv_label_set_text(artistLabel, "Queue Clear");
    lv_label_set_text(songLabel, "");
    lv_label_set_text(playPauseLabel, LV_SYMBOL_STOP);

    mdTime = k_uptime_seconds();
    songPos = 0;
    isPlaying = false;

    k_mutex_unlock(&lvglMutex);
}

struct SongQueueArgs
{
    char** parts;
    size_t partCount;

    char* parentStr;
    size_t textLen;
    struct k_work_delayable task;
};

static lv_group_t* queueGroup;
static lv_group_t* g;

static void queueButtonHandler(lv_event_t* e);
static void updateQueue(struct k_work* work)
{
    struct SongQueueArgs* sq = CONTAINER_OF(work, struct SongQueueArgs, task.work);
    size_t partCount = 0;
        
    char** parts = nullBreakData(sq->parentStr + 1, sq->textLen - 1, &partCount);
    int8_t queueModifier = sq->parentStr[0] - 64;
    printk("Queue modifier: %d\n", queueModifier);
    
    k_mutex_lock(&lvglMutex, K_FOREVER);

    if(queueModifier == 0)
    {
        //lv_list_clean(queueList);
        for(int i = 0; i < 10; i++)
        {
            lv_obj_t* button = lv_list_add_button(queueList, NULL, parts[i * 2]);
            lv_obj_add_event_cb(button, queueButtonHandler, LV_EVENT_ALL, (void*)(uintptr_t)(parts[i * 2 + 1][0]));
            lv_group_add_obj(queueGroup, button);
            /*
            lv_obj_set_width(card, 128);
            lv_obj_set_height(card, LV_SIZE_CONTENT);
            lv_obj_set_flex_flow(card, LV_FLEX_FLOW_ROW);
            lv_obj_set_scrollbar_mode(card, LV_SCROLLBAR_MODE_OFF);

            lv_obj_add_style(card, &tight, LV_STATE_DEFAULT);
            lv_obj_add_style(card, &tight_aoCard, LV_STATE_DEFAULT);

            lv_obj_add_flag(card, LV_OBJ_FLAG_CLICKABLE);
            lv_obj_add_flag(card, LV_OBJ_FLAG_SCROLL_ON_FOCUS);
            lv_obj_clear_flag(card, LV_OBJ_FLAG_SCROLLABLE);
    
            //lv_obj_add_event_cb(card, cardDelCB, LV_EVENT_CLICKED, NULL);

            //lv_group_add_obj(g, card);
        
    
            //Text container
            lv_obj_t* textContainer = lv_obj_create(card);
            lv_obj_set_width(textContainer, lv_pct(100));
            lv_obj_set_height(textContainer, LV_SIZE_CONTENT);
            lv_obj_set_flex_flow(textContainer, LV_FLEX_FLOW_COLUMN);
            lv_obj_set_scrollbar_mode(textContainer, LV_SCROLLBAR_MODE_OFF);

            lv_obj_add_style(textContainer, &tight, LV_STATE_DEFAULT);

            lv_obj_add_flag(textContainer, LV_OBJ_FLAG_CLICKABLE); 
            lv_obj_clear_flag(textContainer, LV_OBJ_FLAG_CLICK_FOCUSABLE);
    

            //Title (appname)
            lv_obj_t* titleLabel = lv_label_create(textContainer);
            lv_label_set_long_mode(titleLabel, LV_LABEL_LONG_SCROLL_CIRCULAR);

            lv_obj_add_style(titleLabel, &tight, LV_STATE_DEFAULT);
            lv_obj_add_style(titleLabel, &tight_aoTitle, LV_STATE_DEFAULT);
    
            lv_label_set_text(titleLabel, "TEST");
    

            /*
            //Subtitle (title)
            lv_obj_t* subtitleLabel = lv_label_create(textContainer);
            lv_label_set_long_mode(subtitleLabel, LV_LABEL_LONG_SCROLL_CIRCULAR);

            lv_obj_add_style(subtitleLabel, &tight, LV_STATE_DEFAULT);
            lv_obj_add_style(subtitleLabel, &tight_aoTitle, LV_STATE_DEFAULT);
    
            lv_label_set_text(subtitleLabel, "TEST2");
            */
        }
    }

    k_mutex_unlock(&lvglMutex);
    
    k_free(sq->parentStr);
    k_free(sq);
}

static struct BTDePacket musicQueue = {0};
static ssize_t queueSet(struct bt_conn *conn, const struct bt_gatt_attr *attr,
			     const void *buf, uint16_t len, uint16_t offset,
			     uint8_t flags)
{
    //printk("Music queue characteristic written to\n");
    if(processPackets((char*)buf, len, &musicQueue) == DONE)
    {
        struct SongQueueArgs* sqArgs = (struct SongQueueArgs*)k_calloc(1, sizeof(struct SongQueueArgs));
        sqArgs->parentStr = musicQueue.finalStr;
        sqArgs->textLen = musicQueue.textLen;
        k_work_init((struct k_work*)&sqArgs->task, updateQueue);
        k_work_schedule(&sqArgs->task, K_NO_WAIT);
    }

    return len;
}

static struct BTDePacket musicMetadata = {0};
static ssize_t metadataSet(struct bt_conn *conn, const struct bt_gatt_attr *attr,
			     const void *buf, uint16_t len, uint16_t offset,
			     uint8_t flags)
{
    if(processPackets((char*)buf, len, &musicMetadata) == DONE)
    {
        size_t partCount = 0;
        char** parts = nullBreakData(musicMetadata.finalStr, musicMetadata.textLen, &partCount);
        for(int i = 0; i < musicMetadata.textLen; i++)
        {
            //printk("%c", (char)musicMetadata.finalStr[i]);
        }
        //printk("\n");
        if(partCount == 1)
        {
            if(strcmp(musicMetadata.finalStr, "KILL") == 0)
            {
                //run close logic
                printk("Kill command recieved\n");
                k_work_init((struct k_work*)&csdTask, clearSongDeets);
                k_work_schedule(&csdTask, K_NO_WAIT);
            }
            else
            {
                printk("Invalid music metadata format\n");
            }
            k_free(parts);
            k_free(musicMetadata.finalStr);
            return len;
        }

        else if(partCount != 6)
        {
            printk("Invalid music metadata format\n");
            k_free(parts);
            k_free(musicMetadata.finalStr);
            return len;
        }

        char* song      = parts[0];
        char* artist    = parts[1];
        char* sLength   = parts[3];
        char* sPosition = parts[4];
        char* isPlaying = parts[5];

        k_free(parts);

        struct SongArgs* notif = (struct SongArgs*)k_calloc(1, sizeof(struct SongArgs));

        notif->artist = artist;
        notif->song = song;
        notif->length = atoi(sLength);
        notif->position = atoi(sPosition);
        notif->isPlaying = (isPlaying[0] == '1');
        notif->parentStr = musicMetadata.finalStr;

        k_work_init((struct k_work*)&notif->task, updateSongDeets);
        k_work_schedule(&notif->task, K_NO_WAIT);
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


static ssize_t cRead(struct bt_conn* conn, const struct bt_gatt_attr* attr,
			    void* buf, uint16_t len, uint16_t offset)
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
                           0, metadataSet, 
                           musicMetadata.inPacket),
    BT_GATT_CHARACTERISTIC(&music_control_char_uuid.uuid,
                           BT_GATT_CHRC_READ | BT_GATT_CHRC_WRITE | BT_GATT_CHRC_NOTIFY,
                           BT_GATT_PERM_READ | BT_GATT_PERM_WRITE, 
                           cRead, cWrite, 
                           buttonSend),
    BT_GATT_CCC(cccCFGChange, BT_GATT_PERM_READ | BT_GATT_PERM_WRITE),
    BT_GATT_CHARACTERISTIC(&music_queue_char_uuid.uuid,
                           BT_GATT_CHRC_READ | BT_GATT_CHRC_WRITE,
                           BT_GATT_PERM_READ | BT_GATT_PERM_WRITE, 
                           0, queueSet, 
                           musicQueue.inPacket),
);

static lv_obj_t* screen;
static lv_obj_t* deetsCont;

App musicControlApp;

static void controlButtonHandler(lv_event_t* e) 
{
    lv_event_code_t code = lv_event_get_code(e);
    uint32_t key = lv_event_get_key(e);

    //printk("Event code: %d, key: %d\n", code, key);
    
    if(code == LV_EVENT_KEY) 
    {
        //for regular button presses
        //printf("Key: %d\nCode: %d\n", key, code);
    
        switch(key)
        {
            case(LV_KEY_LEFT): //up
            {
                //lv_group_focus_obj(deetsCont);
                packetizeSend("2", &music_service.attrs[4]);
                break;
            }

            case(LV_KEY_RIGHT):
            {
                packetizeSend("3", &music_service.attrs[4]);
                break;
            }

            case(LV_KEY_ENTER): // sel
            {
                packetizeSend("1", &music_service.attrs[4]);
                break;
            }
        }
    }

    else if(code == LV_EVENT_LONG_PRESSED_REPEAT)
    {
        lv_group_focus_obj(queueList);
        lv_group_set_editing(queueGroup, false);
        lv_obj_scroll_to_view(queueList, LV_ANIM_ON);
        lv_indev_set_group(indev, queueGroup);
        //musicControlApp.inputGroup = &queueGroup;
    }
}


static void queueButtonHandler(lv_event_t* e) 
{
    lv_event_code_t code = lv_event_get_code(e);
    uint32_t key = lv_event_get_key(e);

    //printk("Event code: %d, key: %d\n", code, key);
    
    if(code == LV_EVENT_KEY) 
    {
        //for regular button presses
        printk("Queue button handler event key\n");
        switch(key)
        {
            case(LV_KEY_LEFT): //up
            {
                //lv_group_focus_obj(deetsCont);
                //packetizeSend("2", &music_service.attrs[4]);
                break;
            }

            case(LV_KEY_RIGHT):
            {
                //packetizeSend("3", &music_service.attrs[4]);
                break;
            }

            case(LV_KEY_ENTER): // sel
            {
                //packetizeSend("1", &music_service.attrs[4]);
                break;
            }
        }
    }

    else if(code == LV_EVENT_LONG_PRESSED_REPEAT)
    {
        printk("Queue button handler longpress\n");
        //lv_group_focus_obj(deetsCont);
        //lv_group_set_editing(g, true);
        lv_obj_scroll_to_view(deetsCont, LV_ANIM_ON);
        //musicControlApp.inputGroup = &g;
    }
}

LV_FONT_DECLARE(Mostane_20);
LV_FONT_DECLARE(Oswald_12);

static const lv_style_const_prop_t titleStyle_props[] = {
    LV_STYLE_CONST_TEXT_FONT(&Mostane_20),
    LV_STYLE_CONST_MAX_WIDTH(128),
    LV_STYLE_CONST_PROPS_END
};
static const LV_STYLE_CONST_INIT(titleStyle, titleStyle_props);

static const lv_style_const_prop_t deetsStyle_props[] = {
    LV_STYLE_CONST_TEXT_FONT(&Oswald_12),
    LV_STYLE_CONST_MAX_WIDTH(96),
    LV_STYLE_CONST_PROPS_END
};
static const LV_STYLE_CONST_INIT(deetsStyle, deetsStyle_props);

void MusicControl(void)
{
    screen = lv_obj_create(0);
    g = lv_group_create();
    queueGroup = lv_group_create();
    printk("Music Control Loaded\n");
    
    //lv_group_focus_freeze(g, true);
    lv_group_set_editing(g, true);
    lv_obj_set_scrollbar_mode(screen, LV_SCROLLBAR_MODE_OFF);
    lv_obj_set_scroll_snap_y(screen, LV_SCROLL_SNAP_START);


    deetsCont = lv_obj_create(screen);
    lv_obj_add_style(deetsCont, &tight, LV_STATE_DEFAULT);

    lv_group_add_obj(g, deetsCont);

    lv_obj_add_event_cb(deetsCont, controlButtonHandler, LV_EVENT_ALL, NULL);
    lv_obj_add_flag(deetsCont, LV_OBJ_FLAG_CLICKABLE);
    lv_obj_add_flag(deetsCont, LV_OBJ_FLAG_SCROLL_ON_FOCUS);
    lv_obj_clear_flag(deetsCont, LV_OBJ_FLAG_CLICK_FOCUSABLE);
    lv_obj_set_scrollbar_mode(deetsCont, LV_SCROLLBAR_MODE_OFF);

    lv_obj_t* titleLabel = lv_label_create(deetsCont);
    lv_obj_set_pos(titleLabel, 0, 4);
    lv_obj_add_style(titleLabel, &titleStyle, LV_STATE_DEFAULT);
    lv_label_set_text(titleLabel, "Music");

    artistLabel = lv_label_create(deetsCont);
    lv_obj_set_pos(artistLabel, 32, 0);
    lv_label_set_long_mode(artistLabel, LV_LABEL_LONG_SCROLL);
    lv_obj_add_style(artistLabel, &deetsStyle, LV_STATE_DEFAULT);

    songLabel = lv_label_create(deetsCont);
    lv_obj_set_pos(songLabel, 32, 12);
    lv_label_set_long_mode(songLabel, LV_LABEL_LONG_SCROLL_CIRCULAR);
    lv_obj_add_style(songLabel, &deetsStyle, LV_STATE_DEFAULT);

    playPauseLabel = lv_label_create(deetsCont);
    lv_obj_set_pos(playPauseLabel, 0, 26);
    lv_obj_add_style(playPauseLabel, &deetsStyle, LV_STATE_DEFAULT);
    //lv_group_focus_obj(screen);
    progressBar = lv_bar_create(deetsCont);
    lv_obj_set_size(progressBar, 96, 14);
    lv_obj_set_pos(progressBar, 32, 26);
    
    lv_label_set_text(artistLabel, "Queue Clear");
    lv_label_set_text(songLabel, "");
    lv_label_set_text(playPauseLabel, LV_SYMBOL_STOP);

    queueList = lv_list_create(screen);
    lv_obj_set_size(queueList, 128, 64);
    lv_obj_set_pos(queueList, 0, 42);
    lv_obj_set_flex_flow(queueList, LV_FLEX_FLOW_COLUMN);
    lv_obj_set_scroll_dir(queueList, LV_DIR_VER);
    lv_obj_set_scroll_snap_y(queueList, LV_SCROLL_SNAP_START);
    lv_obj_add_flag(queueList, LV_OBJ_FLAG_SCROLL_ON_FOCUS);

    lv_obj_add_style(queueList, &listMain, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_add_style(queueList, &listScrollbar, LV_PART_SCROLLBAR | LV_STATE_DEFAULT);
    lv_obj_add_event_cb(queueList, queueButtonHandler, LV_EVENT_ALL, NULL);
    //lv_group_add_obj(queueGroup, queueList);
        
    lv_group_focus_obj(deetsCont);
    k_thread_suspend(k_current_get());
    
    while(1)
    {
        //render
        k_mutex_lock(&lvglMutex, K_FOREVER);
        //do progress bar
        uint32_t delta = k_uptime_seconds() - mdTime;
        if(isPlaying)
        {
            lv_bar_set_value(progressBar, (100 * (songPos + delta))/songLen, LV_ANIM_OFF);
        }
        
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