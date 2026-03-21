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

lv_obj_t* artistLabel;
lv_obj_t* songLabel;
lv_obj_t* playPauseLabel;
static uint32_t mdTime = 0;
static uint32_t pos = 0;
static uint32_t len = 0;
static bool playing = false;

struct SongArgs
{
    char* artist;
    char* song;
    bool isPlaying;//should rework the way this info is sent
    uint32_t length;
    uint32_t position;
    struct k_work_delayable task;
};

static void updateSongDeets(struct k_work* work)
{
    struct SongArgs* md = CONTAINER_OF(work, struct SongArgs, task.work);

    k_mutex_lock(&lvglMutex, K_FOREVER);
    
    lv_label_set_text(artistLabel, md->artist);
    lv_label_set_text(songLabel, md->song);
    lv_label_set_text(playPauseLabel, (md->isPlaying?LV_SYMBOL_PLAY:LV_SYMBOL_PAUSE));

    pos = md->position;
    len = md->length;
    playing = md->isPlaying;

    printk("%d, %d", pos, len);
    k_mutex_unlock(&lvglMutex);

    k_free(md->artist);
    k_free(md->song);
    k_free(md);
}

static struct BTDePacket musicMetadata = {0};
static ssize_t notificationSet(struct bt_conn *conn, const struct bt_gatt_attr *attr,
			     const void *buf, uint16_t len, uint16_t offset,
			     uint8_t flags)
{
    if(processPackets(buf, len, &musicMetadata) == DONE)
    {
        printf("Full music metadata %s\n", musicMetadata.finalStr);

        if(strcmp(musicMetadata.finalStr, "KILL") == 0)
        {
            //run close logic
            printk("Kill command recieved\n");
        }

        else
        {
            char* song      = getPart(musicMetadata.finalStr, "<AD>", "<1>");
            char* artist    = getPart(musicMetadata.finalStr, "<1>", "<2>");
            char* sLength   = getPart(musicMetadata.finalStr, "<3>", "<4>");
            char* sPosition = getPart(musicMetadata.finalStr, "<4>", "<5>");
            char* isPlaying = getPart(musicMetadata.finalStr, "<5>", NULL);

            struct SongArgs* notif = (struct SongArgs*)k_calloc(1, sizeof(struct SongArgs));
            notif->artist = artist;
            notif->song = song;
            notif->length = atoi(sLength);
            notif->position = atoi(sPosition);
            notif->isPlaying = (isPlaying[0] == '1');

            k_free(sLength);
            k_free(sPosition);
            k_free(isPlaying);

            mdTime = k_uptime_seconds();
            k_work_init((struct k_work*)&notif->task, updateSongDeets);
            k_work_schedule(&notif->task, K_NO_WAIT);
        }

        k_free(musicMetadata.finalStr);
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

static void testFunc(lv_event_t* e) 
{
    lv_event_code_t code = lv_event_get_code(e);
    //printf("Key: %d\nCode: %d\n", lv_event_get_key(e), code);
    
    if(code == LV_EVENT_KEY) 
    {

    }
}

LV_FONT_DECLARE(Mostane_20);
LV_FONT_DECLARE(Oswald);

static const lv_style_const_prop_t titleStyle_props[] = {
    LV_STYLE_CONST_TEXT_FONT(&Mostane_20),
    LV_STYLE_CONST_MAX_WIDTH(128),
    LV_STYLE_CONST_PROPS_END
};
static const LV_STYLE_CONST_INIT(titleStyle, titleStyle_props);

static const lv_style_const_prop_t deetsStyle_props[] = {
    LV_STYLE_CONST_TEXT_FONT(&Oswald),
    LV_STYLE_CONST_MAX_WIDTH(96),
    LV_STYLE_CONST_PROPS_END
};
static const LV_STYLE_CONST_INIT(deetsStyle, deetsStyle_props);

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

    lv_obj_t* titleLabel = lv_label_create(screen);
    lv_obj_set_pos(titleLabel, 0, 4);
    lv_obj_add_style(titleLabel, &titleStyle, LV_STATE_DEFAULT);
    lv_label_set_text(titleLabel, "Music");

    artistLabel = lv_label_create(screen);
    lv_obj_set_pos(artistLabel, 32, 0);
    lv_label_set_long_mode(artistLabel, LV_LABEL_LONG_SCROLL);
    lv_obj_add_style(artistLabel, &deetsStyle, LV_STATE_DEFAULT);

    songLabel = lv_label_create(screen);
    lv_obj_set_pos(songLabel, 32, 12);
    lv_label_set_long_mode(songLabel, LV_LABEL_LONG_SCROLL_CIRCULAR);
    lv_obj_add_style(songLabel, &deetsStyle, LV_STATE_DEFAULT);

    playPauseLabel = lv_label_create(screen);
    lv_obj_set_pos(playPauseLabel, 0, 26);
    lv_obj_add_style(playPauseLabel, &deetsStyle, LV_STATE_DEFAULT);
    //lv_group_focus_obj(screen);

    lv_obj_t* progressBar = lv_bar_create(screen);
    lv_obj_set_size(progressBar, 96, 14);
    lv_obj_set_pos(progressBar, 32, 26);

    uint32_t curTime = mdTime;
    k_thread_suspend(k_current_get());
    
    while(1)
    {
        //render
        k_mutex_lock(&lvglMutex, K_FOREVER);
        //do progress bar
        if(playing)
        {
            curTime = k_uptime_seconds();
        }
        uint32_t delta = curTime - mdTime;
        len = MAX(len, 1);
        lv_bar_set_value(progressBar, (100 * (pos + delta))/len, LV_ANIM_ON);

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