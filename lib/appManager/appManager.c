#include <appManager.h>
#include <globals.h>
#include <lvgl.h>
/*
int AppManagerSetup(App* apps, int count)
{
    appCount = count;
    for (int i = 0; i < count; i++)
    {
        //apps[i].stackArea = k_thread_stack_alloc(apps[i].stackSize, 0);
        if (apps[i].stack == NULL)
        {
            printk("Failed to allocate stack for app %s\n", apps[i].name);
            return -1;
        }

        apps[i].threadId = k_thread_create(&apps[i].threadData, apps[i].stack,
                                           apps[i].stackSize,
                                           (k_thread_entry_t)apps[i].mainFunc,
                                           NULL, NULL, NULL,
                                           7, 0, K_FOREVER);
        if (apps[i].threadId == NULL)
        {
            printk("Failed to create thread for app %s\n", apps[i].name);
            return -1;
        }

        printk("App %s setup complete\n", apps[i].name);
    }

    k_thread_start(apps[0].threadId);
    return 0;
}
*/

K_MUTEX_DEFINE(lvglMutex);

int AppManagerSetup(App* apps, int count)
{
    appCount = count;
    appIndex = 0;
    appList = apps;
    for (int i = 0; i < count; i++)
    {
        if (apps[i].threadId == NULL)
        {
            printk("Failed to create thread for app index %d\n", i);
            return -1;
        }

        printk("App index %d setup complete\n", i);
    }

    lv_scr_load(*apps[appIndex].screen);
    k_thread_resume(apps[appIndex].threadId);
    return 0;
}

void appChange(bool reset)
{
    //oldIndex = appIndex;
    k_mutex_lock(&lvglMutex, K_FOREVER);
    k_thread_suspend(appList[appIndex].threadId);
    appIndex++;
    if(appIndex == appCount)
    {
        appIndex = 0;
    }

    lv_scr_load(*appList[appIndex].screen);
    k_thread_resume(appList[appIndex].threadId);
    k_mutex_unlock(&lvglMutex);
    return;
}