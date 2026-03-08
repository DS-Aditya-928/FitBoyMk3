#pragma once

#include <lvgl.h>

int buttonInit(void);

extern lv_indev_t* indev; //might be a neater way to do this only appmanager needs it 
extern struct gpio_dt_spec* onButton; //just for settings

#define UP 13
#define DOWN 12
#define SELECT 14
#define MODESWITCH 15