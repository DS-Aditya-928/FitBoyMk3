#include <lvgl.h>
lv_obj_t* screen2;


void Settings(void)
{
    screen2 = lv_obj_create(0);
    k_thread_suspend(k_current_get());
    printk("Settings Loaded\n");

    lv_obj_t* list = lv_list_create(screen2);
    lv_obj_set_size(list, 128, 64);
    lv_obj_center(list);
    lv_obj_set_style_pad_all(list, 0, 0);
    lv_obj_set_style_pad_row(list, 0, 0);
    lv_obj_set_style_border_width(list, 0, 0);

    static lv_style_t tight;
    lv_style_init(&tight);
    lv_style_set_pad_ver(&tight, 1);
    lv_style_set_pad_gap(&tight, 0);
    lv_style_set_radius(&tight, 0);
    lv_style_set_border_width(&tight, 0);

    lv_obj_t* b1 = lv_list_add_btn(list, LV_SYMBOL_FILE, "New");
    lv_obj_t* b2 = lv_list_add_btn(list, LV_SYMBOL_DIRECTORY, "Open");

    lv_obj_add_style(b1, &tight, 0);
    lv_obj_add_style(b2, &tight, 0);

    while(1)
    {
        //render
        k_mutex_lock(&lvglMutex, K_FOREVER);
        /*
        struct timespec ts;
        clock_gettime(CLOCK_REALTIME, &ts);

        struct tm time_info;
        char bufferTime[6];

        strftime(bufferTime, sizeof(bufferTime), "%H:%M", &time_info);
        lv_label_set_text(time_label, bufferTime);
        */
        
        lv_task_handler();
        k_mutex_unlock(&lvglMutex);
        k_sleep(K_SECONDS(2));
    }
}

K_THREAD_DEFINE(settings_thread, 16384, Settings, NULL, NULL, NULL, 7, 0, 0);
App settingsApp =
{
    .threadId = settings_thread,
    .screen = &screen2,
    .name = "Settings"
};
