#include <zephyr/kernel.h>
#include <zephyr/sys/iterable_sections.h>
#include <lvgl.h>

typedef struct 
{
    k_tid_t threadId;
    lv_obj_t** screen;
    //void (*init)(void);
    //void (*deinit)(void);
    //void (*handleEvent)(int event);

    const char* name;
} App;

/*
extern int appCount;// = 0;
extern int appIndex;// = -1;
extern App* appList;
*/

//int AppManagerSetup(App*, int);
int AppManagerSetup(App* apps, int count);
void appChange(bool);