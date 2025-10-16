#include "list.h"
#include <stdlib.h>

list *listCreate() {
    list *l = malloc(sizeof(list));
    if(!l) return NULL;

    l->head = NULL;
    l->tail = NULL;
    l->size = 0;
    return l;
}

void listDestroy(list *l) {
    if(!l) return;

    listNode *current = l->head;
    while(current) {
        listNode *next = current->next;
        free(current);
        current = next;
    }
    free(l);
}

int *listFront(const list *l) {
    return l->head ? &l->head->value : NULL;
}

int *listBack(const list *l) {
    return l->tail ? &l->tail->value : NULL;
}

int *listGet(const list *l, const size_t index) {
    if(index >= l->size) return NULL;

    listNode *current = l->head;
    for(size_t i = 0; i < index; i++) {
        current = current->next;
    }
    return &(current->value);
}

int listSet(const list *l, const size_t index, const int value) {
    if(index >= l->size) return 0;

    listNode *current = l->head;
    for(size_t i = 0; i < index; i++) {
        current = current->next;
    }
    current->value = value;
    return 1;
}

int listPushFront(list *l, const int value) {
    listNode *newNode = malloc(sizeof(listNode));
    if(!newNode) return 0;
    newNode->value = value;
    newNode->next = l->head;
    newNode->prev = NULL;
    if(l->head) l->head->prev = newNode;
    l->head = newNode;
    if(!l->tail) l->tail = newNode;
    l->size++;
    return 1;
}

int listPushBack(list *l, const int value) {
    listNode *newNode = malloc(sizeof(listNode));
    if(!newNode) return 0;
    newNode->value = value;
    newNode->prev = l->tail;
    newNode->next = NULL;
    if(l->tail) l->tail->next = newNode;
    l->tail = newNode;
    if(!l->head) l->head = newNode;
    l->size++;
    return 1;
}

int listPopBack(list *l) {
    if(!l->tail) return 0;

    listNode *aux = l->tail->prev;
    free(l->tail);
    l->tail = aux;
    if(aux) aux->next = NULL;
    else l->head = NULL;
    l->size--;
    return 1;
}

int listPopFront(list *l) {
    if(!l->head) return 0;

    listNode *aux = l->head->next;
    free(l->head);
    l->head = aux;
    if(aux) aux->prev = NULL;
    else l->tail = NULL;
    l->size--;
    return 1;
}

void listClear(list* l) {
    listNode* current = l->head;
    while (current) {
        listNode* next = current->next;
        free(current);
        current = next;
    }
    l->head = l->tail = NULL;
    l->size = 0;
}

size_t listSize(const list *l) {
    return l->size;
}
int listEmpty(const list *l) {
    return l->size == 0;
}
