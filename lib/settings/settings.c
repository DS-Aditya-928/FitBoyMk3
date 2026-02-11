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
    
    static lv_style_t monoIcon;
    lv_style_init(&monoIcon);
    // Set a fixed width for the icon element
    lv_style_set_min_width(&monoIcon, 20);
    lv_style_set_text_align(&monoIcon, LV_TEXT_ALIGN_CENTER);

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
    lv_style_set_text_font(&tight, &Mostane_20);


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

    lv_obj_t* flash = lv_list_add_button(list, LV_SYMBOL_DOWNLOAD, "Flash Firmware");
    lv_obj_t* power = lv_list_add_button(list, LV_SYMBOL_POWER, "Power Off");

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
    
    lv_obj_add_style(lv_obj_get_child(flash, 0), &monoIcon, 0);
    lv_obj_add_style(lv_obj_get_child(power, 0), &monoIcon, 0);

    lv_group_add_obj(g, flash);
    lv_group_add_obj(g, power);

    k_thread_suspend(k_current_get());
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