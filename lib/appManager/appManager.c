#include <appManager.h>

#include <lvgl.h>
#include <buttons.h>
#include <appBasic.h>

K_MUTEX_DEFINE(lvglMutex);

int appCount = 0;
int appIndex = -1;
App* appList = 0;

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
    lv_indev_set_group(indev, *apps[appIndex].inputGroup);
    k_thread_resume(apps[appIndex].threadId);
    return 0;
}

void appChange(bool reset)
{
    k_mutex_lock(&lvglMutex, K_FOREVER);
    k_thread_suspend(appList[appIndex].threadId);
    appIndex++;
    if(appIndex == appCount)
    {
        appIndex = 0;
    }

    lv_scr_load(*appList[appIndex].screen);
    lv_indev_set_group(indev, *appList[appIndex].inputGroup);
    k_thread_resume(appList[appIndex].threadId);
    k_mutex_unlock(&lvglMutex);
}