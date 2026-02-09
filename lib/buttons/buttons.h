#pragma once

#include <lvgl.h>

int buttonInit(void);

extern struct k_sem buttonInput_sem;
extern lv_indev_t* indev;

#define UP 13
#define DOWN 12
#define SELECT 14
#define MODESWITCH 15
/*
13 - UP
12 - DOWN
14 - SELECT
15 - MODESWITCH
*/