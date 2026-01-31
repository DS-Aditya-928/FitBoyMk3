#include <zephyr/kernel.h>
#include <zephyr/sys/iterable_sections.h>

typedef struct 
{
    k_tid_t threadId;
    //void (*init)(void);
    //void (*deinit)(void);
    //void (*handleEvent)(int event);

    const char* name;
} App;

static int appCount = 0;
static int appIndex = -1;
static k_tid_t* appList;

//int AppManagerSetup(App*, int);
int AppManagerSetup(k_tid_t* apps, int count);
void appChange(bool);