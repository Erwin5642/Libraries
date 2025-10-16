#ifndef LIST_H
#define LIST_H

#include <stdint.h>

typedef struct listNode{
    int value;
    struct listNode *prev;
    struct listNode *next;
}listNode;

typedef struct {
    listNode *head;
    listNode *tail;
    size_t size;
}list;

list *listCreate(void);
void listDestroy(list *l);

int *listFront(const list *l);
int *listBack(const list *l);
int *listGet(const list *l, size_t index);
int listSet(const list *l, size_t index, int value);

int listPushFront(list *l, int value);
int listPushBack(list *l, int value);
int listPopBack(list *l);
int listPopFront(list *l);
void listClear(list* l);

size_t listSize(const list *l);
int listEmpty(const list *l);

#endif //LIST_H

