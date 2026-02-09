#pragma once

#include <zephyr/kernel.h>
#include <lvgl.h>

typedef struct 
{
    k_tid_t threadId;
    lv_obj_t** screen;
    lv_group_t** inputGroup;
    //void (*init)(void);
    //void (*deinit)(void);
    //void (*handleEvent)(int event);

    const char* name;
} App;

extern int AppManagerSetup(App* apps, int count);
extern void appChange(bool);