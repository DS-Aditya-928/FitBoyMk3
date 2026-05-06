#include <circularbuffer.h>
#include <stddef.h>
#include <stdbool.h>
#include <string.h>

bool qEnqueue(struct Queue* q, void* item)
{
    if (q->count < (q->size - 1))
    {
        //q->members[q->writeHead] = item;
        memcpy((char*)(q->members) + (q->writeHead * q->memberSize), item, q->memberSize);
        q->writeHead++;
        q->writeHead %= q->size;
        q->count++;
        printk("Enqueued item to queue, write head: %d, count: %d\n", q->writeHead, q->count);
        return true;
    }
    return false;
}

void qDequeue(struct Queue* q, void* returnAddr)
{
    if (q->count > 0)
    {
        memcpy(returnAddr, (char*)(q->members) + (q->readHead * q->memberSize), q->memberSize);
        printk("Dequeued item from queue, read head: %d, count: %d\n", q->readHead, q->count);
        q->readHead++;
        q->readHead %= q->size;
        q->count--;
    }
}