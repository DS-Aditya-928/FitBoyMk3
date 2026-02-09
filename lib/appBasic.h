#pragma once
#include <stdlib.h>

#include <lvgl.h>

#include <appManager.h>
#include <buttons.h>
#include <btManager.h>

extern struct k_mutex lvglMutex;
extern struct gpio_dt_spec* onButton;