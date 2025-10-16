#include <stdio.h>

#include "list.h"

int main() {
    list *l = listCreate();

    printf("listPushBack()\n");
    for(int i = 0; i < 200; i++) {
        if(!listPushBack(l, i)) {
            printf("listPushBack() failed\n");
        }
    }

    printf("listGet()\n");
    for(int i = 0; i < 200; i++) {
        printf("%d\n", *listGet(l, i));
    }

    printf("listPopFront()\n");
    for(int i = 0; i < 200; i++) {
        printf("listFront()\n");
        printf("%d\n", *listFront(l));
        if(!listPopFront(l)) {
            printf("listPopFront() failed\n");
        }
    }

    printf("listPushFront()\n");
    for(int i = 0; i < 200; i++) {
        if(!listPushFront(l, i)) {
            printf("listPushFront() failed\n");
        }
    }

    printf("listGet()\n");
    for(int i = 0; i < 200; i++) {
        printf("%d\n", *listGet(l, i));
    }

    printf("listPopBack()\n");
    for(int i = 0; i < 200; i++) {
        printf("listBack()\n");
        printf("%d\n", *listBack(l));
        if(!listPopBack(l)) {
            printf("listPopBack() failed\n");
        }
    }

    printf("listEmpty()\n");
    printf("%d\n", listEmpty(l));
    listPushBack(l, 1);
    printf("listSize()\n");
    printf("%llu\n", listSize(l));

    printf("%d %d %llu\n", l->head->value, l->tail->value, l->size);

    listDestroy(l);
    l = NULL;

    return 0;
}