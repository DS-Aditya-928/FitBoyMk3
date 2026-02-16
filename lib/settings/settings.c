#include <zephyr/drivers/gpio.h>
#include <zephyr/drivers/i2c.h>
#include <zephyr/sys/reboot.h>
#include <zephyr/sys/poweroff.h>
#include <hal/nrf_power.h>

#include <appBasic.h>

#include <settings.h>

struct k_work_delayable task;
lv_obj_t* screen;
LV_FONT_DECLARE(Mostane_20);

void displayExit(struct k_work *work)
{
    //lv_obj_clean(screen);
    nrf_power_gpregret_set(NRF_POWER, 0, 0x57);
    sys_reboot(SYS_REBOOT_COLD);
}

static void flashButtonCB(lv_event_t* e)
{
    printk("Flash button click\n");
    lv_obj_t* s2 = lv_obj_create(NULL);
    lv_obj_t* mainLabel = lv_label_create(s2);
    lv_obj_set_style_text_font(mainLabel, &Mostane_20, 0);
    lv_label_set_text(mainLabel, "in flash mode...\n");
    lv_obj_align(mainLabel, LV_ALIGN_TOP_LEFT, 0, 0);
    lv_screen_load(s2);
    
    k_work_init((struct k_work*)&task, displayExit);
    k_work_schedule(&task, K_MSEC(750));
}

static void powerButtonCB(lv_event_t* e)
{
    const struct device* i2c = DEVICE_DT_GET(DT_NODELABEL(i2c0));

    int x = 0;
    uint8_t mpu_sleep_cmd[] = {0x6B, 0x40}; 
    x = i2c_write(i2c, mpu_sleep_cmd, sizeof(mpu_sleep_cmd), 0x68);
    printk("MPU sleep command write returned %d\n", x);

    uint8_t oled_sleep_cmd[] = {0x00, 0xAE};
    x = i2c_write(i2c, oled_sleep_cmd, sizeof(oled_sleep_cmd), 0x3C);
    printk("OLED sleep command write returned %d\n", x);

    gpio_pin_interrupt_configure_dt(onButton, GPIO_INT_LEVEL_ACTIVE);

    sys_poweroff();
}

static const lv_style_const_prop_t monoIcon_props[] = {
    LV_STYLE_CONST_MIN_WIDTH(20),
    LV_STYLE_CONST_TEXT_ALIGN(LV_TEXT_ALIGN_CENTER),
    LV_STYLE_CONST_PROPS_END
};
static const LV_STYLE_CONST_INIT(monoIcon, monoIcon_props);

#define TIGHT_STYLE_PROPS_BASE \
    LV_STYLE_CONST_PAD_ROW(1), \
    LV_STYLE_CONST_RADIUS(0), \
    LV_STYLE_CONST_BORDER_WIDTH(0), \
    LV_STYLE_CONST_OUTLINE_WIDTH(0), \
    LV_STYLE_CONST_BORDER_SIDE(LV_BORDER_SIDE_NONE), \
    LV_STYLE_CONST_BG_OPA(LV_OPA_COVER), \
    LV_STYLE_CONST_TEXT_FONT(&Mostane_20)
    
static const lv_style_const_prop_t tight_props[] = {
    TIGHT_STYLE_PROPS_BASE,
    LV_STYLE_CONST_PAD_COLUMN(5),
    LV_STYLE_CONST_BG_COLOR(LV_COLOR_MAKE(0xFF, 0xFF, 0xFF)), // White
    LV_STYLE_CONST_TEXT_COLOR(LV_COLOR_MAKE(0x00, 0x00, 0x00)), // Black
    LV_STYLE_CONST_PROPS_END
};
static const LV_STYLE_CONST_INIT(tight, tight_props);

static const lv_style_const_prop_t tightSel_props[] = {
    TIGHT_STYLE_PROPS_BASE,
    LV_STYLE_CONST_PAD_COLUMN(15), 
    LV_STYLE_CONST_BG_COLOR(LV_COLOR_MAKE(0xFF, 0xFF, 0xFF)),
    LV_STYLE_CONST_TEXT_COLOR(LV_COLOR_MAKE(0x00, 0x00, 0x00)),
    LV_STYLE_CONST_PROPS_END
};
static const LV_STYLE_CONST_INIT(tightSel, tightSel_props);

static const lv_style_const_prop_t tightSelClick_props[] = {
    TIGHT_STYLE_PROPS_BASE,
    LV_STYLE_CONST_PAD_COLUMN(15),
    LV_STYLE_CONST_BG_COLOR(LV_COLOR_MAKE(0x00, 0x00, 0x00)), // Inverted: Black bg
    LV_STYLE_CONST_TEXT_COLOR(LV_COLOR_MAKE(0xFF, 0xFF, 0xFF)), // Inverted: White text
    LV_STYLE_CONST_PROPS_END
};
static const LV_STYLE_CONST_INIT(tightSelClick, tightSelClick_props);

lv_obj_t* lvglRam;
lv_obj_t* heapRam;

void ramUpdate()
{
    lv_mem_monitor_t mon;
    lv_mem_monitor(&mon);
    lv_obj_t * lvglLabel = lv_obj_get_child(lvglRam, 1);
    lv_label_set_text_fmt(lvglLabel, "LVGL: %d%%", mon.used_pct);

    size_t x = getHeapUsage();
    lv_obj_t * heapLabel = lv_obj_get_child(heapRam, 1);
    lv_label_set_text_fmt(heapLabel, "Heap: %zu B", x);
}

static lv_group_t* g;
void Settings(void)
{
    screen = lv_obj_create(0);
    g = lv_group_create();
    printk("Settings Loaded\n");

    lv_obj_t* list = lv_list_create(screen);
    lv_obj_set_size(list, 128, 64);
    lv_obj_center(list);
    lv_obj_set_style_pad_all(list, 0, 0);
    lv_obj_set_style_pad_row(list, 0, 0);
    lv_obj_set_style_border_width(list, 0, 0);

    lvglRam = lv_list_add_button(list, LV_SYMBOL_DIRECTORY, "LVGL: 0%");
    heapRam = lv_list_add_button(list, LV_SYMBOL_DIRECTORY, "Heap: 2000 B");
    lv_obj_t* flash = lv_list_add_button(list, LV_SYMBOL_DOWNLOAD, "Flash Firmware");
    lv_obj_t* power = lv_list_add_button(list, LV_SYMBOL_POWER, "Power Off");

    lv_obj_add_style(lvglRam, &tight, LV_STATE_DEFAULT);
    lv_obj_add_style(lvglRam, &tightSel, LV_STATE_FOCUSED);
    lv_obj_set_height(lvglRam, LV_SIZE_CONTENT);
    lv_obj_add_style(lvglRam, &tightSelClick, LV_STATE_PRESSED);
    lv_obj_remove_style(lvglRam, NULL, LV_STATE_FOCUS_KEY);

    lv_obj_add_style(heapRam, &tight, LV_STATE_DEFAULT);
    lv_obj_add_style(heapRam, &tightSel, LV_STATE_FOCUSED);
    lv_obj_set_height(heapRam, LV_SIZE_CONTENT);
    lv_obj_add_style(heapRam, &tightSelClick, LV_STATE_PRESSED);
    lv_obj_remove_style(heapRam, NULL, LV_STATE_FOCUS_KEY);

    lv_obj_add_style(flash, &tight, LV_STATE_DEFAULT);
    lv_obj_add_style(flash, &tightSel, LV_STATE_FOCUSED);
    lv_obj_set_height(flash, LV_SIZE_CONTENT);
    lv_obj_add_event_cb(flash, flashButtonCB, LV_EVENT_CLICKED, NULL);
    lv_obj_add_style(flash, &tightSelClick, LV_STATE_PRESSED);
    lv_obj_remove_style(flash, NULL, LV_STATE_FOCUS_KEY);

    lv_obj_add_style(power, &tight, LV_STATE_DEFAULT);
    lv_obj_add_style(power, &tightSel, LV_STATE_FOCUSED);
    lv_obj_set_height(power, LV_SIZE_CONTENT);
    lv_obj_add_event_cb(power, powerButtonCB, LV_EVENT_CLICKED, NULL);
    lv_obj_add_style(power, &tightSelClick, LV_STATE_PRESSED);
    lv_obj_remove_style(power, NULL, LV_STATE_FOCUS_KEY); //just because the default style here isnt what we want.
    
    lv_obj_add_style(lv_obj_get_child(lvglRam, 0), &monoIcon, 0);
    lv_obj_add_style(lv_obj_get_child(heapRam, 0), &monoIcon, 0);
    lv_obj_add_style(lv_obj_get_child(flash, 0), &monoIcon, 0);
    lv_obj_add_style(lv_obj_get_child(power, 0), &monoIcon, 0);

    lv_group_add_obj(g, lvglRam);
    lv_group_add_obj(g, heapRam);
    lv_group_add_obj(g, flash);
    lv_group_add_obj(g, power);

    k_thread_suspend(k_current_get());
    struct k_timer timer;
    k_timer_init(&timer, ramUpdate, NULL);
    k_timer_start(&timer, K_SECONDS(1), K_SECONDS(1));
    while(1)
    {
        //render
        k_mutex_lock(&lvglMutex, K_FOREVER);
        lv_task_handler();
        k_mutex_unlock(&lvglMutex);
        k_sleep(K_MSEC(5));
    }
}

K_THREAD_DEFINE(settings_thread, 16384, Settings, NULL, NULL, NULL, 7, 0, 0);
App settingsApp =
{
    .threadId = settings_thread,
    .screen = &screen,
    .inputGroup = &g,
    .name = "Settings"
};