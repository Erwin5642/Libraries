#include "stack.h"
#include <stdlib.h>

#include "vector.h"

struct stack{
    vector *v;
};

stack *stackCreate() {
    stack *s = malloc(sizeof(stack));
    if(!s) return NULL;
    vector *v = vectorCreate();
    if(!v) {
        free(s);
        return NULL;
    }
    s->v = v;
    return s;
}

void stackDestroy(stack *s) {
    vectorDestroy(s->v);
    free(s);
}

int stackPush(const stack *s, const int value) {
    return vectorPushBack(s->v, value);
}

int stackPop(const stack *s) {
    return vectorPopBack(s->v);
}

int *stackTop(const stack *s) {
    return vectorBack(s->v);
}

size_t stackSize(const stack *s) {
    return vectorSize(s->v);
}

int stackEmpty(const stack *s) {
    return vectorEmpty(s->v);
}