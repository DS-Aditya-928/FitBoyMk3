#include <stdlib.h>
#include "linkedlist.h"

void listInit(struct LinkedList* list, size_t cap) 
{
    list->head = NULL;
    list->tail = NULL;
    list->size = 0;
    list->cap = cap;
}

void listAppend(struct LinkedList* list, void* data) 
{
    struct LinkedListNode* newNode = (struct LinkedListNode*)k_malloc(sizeof(struct LinkedListNode));
    newNode->data = data;
    newNode->next = NULL;

    if(list->size == list->cap) 
    {
        listPop(list);
    }

    if(list->size == 0) 
    {
        list->head = newNode;
        list->tail = newNode;
    }
    else 
    {
        list->tail->next = newNode;
        list->tail = newNode;
    }
    list->size++;
}

void listRemove(struct LinkedList* list, void* data) 
{
    struct LinkedListNode* current = list->head;
    struct LinkedListNode* previous = NULL;

    while(current != NULL) 
    {
        if(current->data == data) 
        {
            if(previous == NULL) 
            {
                list->head = current->next;
            }

            else 
            {
                previous->next = current->next;
            }

            if(current == list->tail) 
            {
                list->tail = previous;
            }

            k_free(current);
            list->size--;
            return;
        }
        previous = current;
        current = current->next;
    }
}

void* listPop(struct LinkedList* list)
{
    if(list->size == 0) return NULL;

    struct LinkedListNode* current = list->head;
    struct LinkedListNode* previous = NULL;

    while(current->next != NULL) 
    {
        previous = current;
        current = current->next;
    }

    if(previous == NULL) 
    {
        list->head = NULL;
        list->tail = NULL;
    }
    else 
    {
        previous->next = NULL;
        list->tail = previous;
    }

    void* tR = current->data;
    k_free(current);
    list->size--;
    return tR;
}

void* listPeek(struct LinkedList* list) 
{
    if(list->size == 0) return NULL;
    return list->tail->data;
}