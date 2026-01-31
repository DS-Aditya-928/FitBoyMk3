
void Settings(void)
{
    k_thread_suspend(k_current_get());
    printk("Settings Loaded\n");

    lv_obj_t *time_label = lv_label_create(lv_scr_act());
    //lv_obj_t *minute_label = lv_label_create(lv_scr_act());
    lv_obj_t *second_label = lv_label_create(lv_scr_act());
    lv_obj_t *day_label = lv_label_create(lv_scr_act());

    lv_obj_set_pos(time_label, 10, 0);
    while(1)
    {
        //render
        
        struct timespec ts;
        clock_gettime(CLOCK_REALTIME, &ts);

        struct tm time_info;
        char bufferTime[6];

        strftime(bufferTime, sizeof(bufferTime), "%H:%M", &time_info);
        lv_label_set_text(time_label, bufferTime);
        
        lv_task_handler();
        k_sleep(K_SECONDS(2));
        //wait
    }
}

K_THREAD_DEFINE(settings_thread, 16384, Settings, NULL, NULL, NULL, 7, 0, 0);
