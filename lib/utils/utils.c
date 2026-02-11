#include "utils.h"
#include <string.h>
#include <stdlib.h>

void trim(char *s) 
{
    if (!s) return;
    char *p = s;
    int l = strlen(p);
    while(l > 0 && isspace((unsigned char)p[l - 1])) p[--l] = 0;
    while(*p && isspace((unsigned char)*p)) ++p, --l;
    memmove(s, p, l + 1);
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

    char* res = malloc(len + 1);
    if (res) 
    {
        strncpy(res, startPtr, len);
        res[len] = '\0';
    }

    return res;
}

