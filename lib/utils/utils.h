#include <stddef.h>

char* getPart(const char* src, const char* startTag, const char* endTag);
char** nullBreakData(const char* src, size_t strLen, size_t* outCount);
void trim(char *s);
size_t getHeapUsage(void);
void print_heap_stats(void);
void print_lvgl_heap_usage(void);