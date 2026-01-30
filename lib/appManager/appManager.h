#include <zephyr/kernel.h>
#include <zephyr/sys/iterable_sections.h>

typedef struct 
{
    k_tid_t threadId;
    void (*init)(void);
    void (*deinit)(void);
    void (*handleEvent)(int event);
} App;

static int appCount = 0;
static int appIndex = -1;

AppManagerSetup(App apps[], int count)
{
    appCount = count;
    appIndex = 0;
    for (int i = 1; i < count; i++)
    {
        
        apps[i].init();
    }
}