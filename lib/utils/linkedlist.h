struct LinkedListNode 
{
    void* data;
    struct LinkedListNode* next;
};

struct LinkedList
{
    struct LinkedListNode* head;
    struct LinkedListNode* tail;
    size_t size;
    size_t cap;
};

void listInit(struct LinkedList* list, size_t cap);
void listPrepend(struct LinkedList* list, void* data);
void listRemove(struct LinkedList* list, void* data);
void* listPeek(struct LinkedList* list);
void* listPeekHead(struct LinkedList* list);
void* listPop(struct LinkedList* list);
