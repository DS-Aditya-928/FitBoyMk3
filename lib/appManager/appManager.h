#include <zephyr/kernel.h>
#include <zephyr/sys/iterable_sections.h>

typedef struct 
{
    k_tid_t threadId;
    //void (*init)(void);
    //void (*deinit)(void);
    //void (*handleEvent)(int event);
    void (*mainFunc)(void);
    struct z_thread_stack_element* stack;
    size_t stackSize;
    struct k_thread threadData;

    const char* name;
} App;

static int appCount = 0;
static int appIndex = -1;

int AppManagerSetup(App*, int);