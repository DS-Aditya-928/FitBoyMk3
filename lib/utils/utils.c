#include "utils.h"
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <zephyr/sys/sys_heap.h>
#include <zephyr/kernel.h>
#include <lvgl.h>

void trim(char *s) 
{
    if (!s || *s == 0) return;

    size_t len = strlen(s);
    char *start = s;
    char *end = s + len - 1;
    while (*start && isspace((unsigned char)*start)) 
    {
        start++;
    }

    while (end > start && isspace((unsigned char)*end)) 
    {
        end--;
    }

    size_t newLen = (start > end) ? 0 : (end - start + 1);

    if (start != s) {
        memmove(s, start, newLen);
    }
    
    s[newLen] = 0;
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

char** nullBreakData(const char* src, size_t strLen, size_t* outCount)
{
    int numEntities = 0;
    size_t accumulator = 0;
    for(int i = 0; i < strLen; i++)
    {
        if(src[i] == 0)
        {
            numEntities++;
        }
    }

    printk("Num entities: %d\n", numEntities);
    char** entities = k_malloc(sizeof(char*) * numEntities);

    for(int i = 0, j = 0; i < strLen && j < numEntities; i++)
    {
        if(src[i] == 0)
        {
            size_t entityLen = &src[i] - &src[accumulator];
            char* entity = k_malloc(entityLen + 1);
            strncpy(entity, &src[accumulator], entityLen);
            entity[entityLen] = '\0';
            entities[j++] = entity;
            accumulator = i + 1;
        }
    }

    if(outCount)
    {
        *outCount = numEntities;
    }

    return entities;
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

    printk("LVGL Memory Stats:\n");
    printk("  Total: %d bytes\n", mon.total_size);
    printk("  Free:  %d bytes\n", mon.free_size);
    printk("  Used:  %d%%\n", mon.used_pct);
    printk("  Frag:  %d%%\n", mon.frag_pct);
    printk("  Max Used: %d bytes\n", mon.max_used);
}

size_t getHeapUsage(void)
{
    struct sys_memory_stats stats;
    int ret;
    ret = sys_heap_runtime_stats_get(&_system_heap, &stats);

    return(stats.allocated_bytes);
}