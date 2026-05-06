#include <stddef.h>
#include <stdbool.h>

struct Queue
{
    void* members;
    size_t size;
    size_t count;
    size_t memberSize;
    size_t readHead;
    size_t writeHead;
};


#define QUEUE_INIT(name, dtype, sz) \
    struct Queue name = { .members = (dtype[sz]){{0}}, .size = sz, .count = 0, .memberSize = sizeof(dtype), .readHead = 0, .writeHead = 0 }


bool qEnqueue(struct Queue* q, void* item);
void qDequeue(struct Queue* q, void* returnAddr);