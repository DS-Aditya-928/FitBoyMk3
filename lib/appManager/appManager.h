#pragma once

#include <zephyr/kernel.h>
#include <lvgl.h>

typedef struct 
{
    k_tid_t threadId;
    lv_obj_t** screen;
    lv_group_t** inputGroup;
    
    uint8_t numInputGroups;
    uint8_t inputGroupIndex;
    lv_group_t*** inputGroups;

    const char* name;
} App;

extern struct k_mutex lvglMutex;
int AppManagerSetup(App* apps, int count);
void appChange(bool resetToFirst);
void setActiveInputGroup(App* app, uint8_t index);