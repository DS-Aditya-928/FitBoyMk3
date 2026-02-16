#include "utils.h"
#include <string.h>
#include <stdlib.h>
#include <zephyr/sys/sys_heap.h>
#include <zephyr/kernel.h>
#include <lvgl.h>

void trim(char *s) 
{
    if (!s) return;
    char *p = s;
    int l = strlen(p);
    while(l > 0 && isspace((unsigned char)p[l - 1])) p[--l] = 0;
    while(*p && isspace((unsigned char)*p)) ++p, --l;
    k_memmove(s, p, l + 1);
}

char* getPart(const char* src, const char* startTag, const char* endTag) 
{
    char* startPtr = strstr(src, startTag);
    if (!startPtr) return NULL;
    
    startPtr += strlen(startTag);
    
    size_t len;
    if (endTag) 
    {
        char *endPtr = strstr(startPtr, endTag);
        if (!endPtr) return NULL;
        len = endPtr - startPtr;
    } 
    
    else 
    {
        len = strlen(startPtr);
    }

    char* res = k_malloc(len + 1);
    if (res) 
    {
        strncpy(res, startPtr, len);
        res[len] = '\0';
    }

    return res;
}


extern struct sys_heap _system_heap;

void print_heap_stats(void) 
{
    struct sys_memory_stats stats;
    int ret;

    // Retrieve stats
    ret = sys_heap_runtime_stats_get(&_system_heap, &stats);

    if (ret == 0) 
    {
        printk("Heap Statistics:\n");
        printk("  Free:      %zu bytes\n", stats.free_bytes);
        printk("  Allocated: %zu bytes\n", stats.allocated_bytes);
        printk("  Max Usage: %zu bytes\n", stats.max_allocated_bytes);
    } 
    else 
    {
        printk("Failed to get heap statistics (%d)\n", ret);
    }
}

void print_lvgl_heap_usage(void) 
{
    lv_mem_monitor_t mon;
    lv_mem_monitor(&mon);

    printf("LVGL Memory Stats:\n");
    printf("  Total: %d bytes\n", mon.total_size);
    printf("  Free:  %d bytes\n", mon.free_size);
    printf("  Used:  %d%%\n", mon.used_pct);
    printf("  Frag:  %d%%\n", mon.frag_pct);
    printf("  Max Used: %d bytes\n", mon.max_used);
}

size_t getHeapUsage(void)
{
    struct sys_memory_stats stats;
    int ret;
    ret = sys_heap_runtime_stats_get(&_system_heap, &stats);

    return(stats.allocated_bytes);
}