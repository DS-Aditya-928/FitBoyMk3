#include <zephyr/bluetooth/bluetooth.h>
#include <zephyr/posix/time.h>
#include <ctype.h>
#include <time.h>
#include <globals.h>

extern App mainMenuApp;
/*
K_THREAD_STACK_DEFINE(mmstack, 16384);
App mainMenuApp = {
    .mainFunc = MainMenu,
    .stack = mmstack,
    .stackSize = K_THREAD_STACK_SIZEOF(mmstack),
    .name = "MainMenu"
};
*/