#include <circularbuffer.h>
#include <stddef.h>
#include <stdbool.h>
#include <string.h>

bool qEnqueue(struct Queue* q, void* item)
{
    if (q->count < q->size)
    {
        memcpy((char*)(q->members) + (q->writeHead * q->memberSize), item, q->memberSize);
        q->lastWriteHead = q->writeHead;
        q->writeHead++;
        q->writeHead %= q->size;
        q->count++;
        return true;
    }
    return false;
}

bool peekLastEnqueued(struct Queue* q, void* returnAddr)
{
    if (q->count > 0)
    {
        memcpy(returnAddr, (char*)(q->members) + (q->lastWriteHead * q->memberSize), q->memberSize);
        return true;
    }
    return false;
}

void modifyLastEnqueued(struct Queue* q, void* item)
{
    if (q->count > 0)
    {
        memcpy((char*)(q->members) + (q->lastWriteHead * q->memberSize), item, q->memberSize);
    }
}

void qDequeue(struct Queue* q, void* returnAddr)
{
    if (q->count > 0)
    {
        memcpy(returnAddr, (char*)(q->members) + (q->readHead * q->memberSize), q->memberSize);
        q->readHead++;
        q->readHead %= q->size;
        q->count--;
    }
}

void qPeekDequeue(struct Queue* q, void* returnAddr)
{
    if (q->count > 0)
    {
        memcpy(returnAddr, (char*)(q->members) + (q->readHead * q->memberSize), q->memberSize);
    }
}