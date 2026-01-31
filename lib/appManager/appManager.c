#include <appManager.h>

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

int AppManagerSetup(k_tid_t* apps, int count)
{
    appCount = count;
    appIndex = 0;
    appList = apps;
    for (int i = 0; i < count; i++)
    {
        if (apps[i] == NULL)
        {
            printk("Failed to create thread for app index %d\n", i);
            return -1;
        }

        printk("App index %d setup complete\n", i);
    }

    k_thread_resume(apps[appIndex]);
    return 0;
}

void appChange(bool reset)
{
    //oldIndex = appIndex;
    k_thread_suspend(appList[appIndex]);
    appIndex++;
    if(appIndex == appCount)
    {
        appIndex = 0;
    }
    k_thread_resume(appList[appIndex]);

    return;
}