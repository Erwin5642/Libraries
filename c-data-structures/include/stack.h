#ifndef STACK_H
#define STACK_H

#include <stdint.h>

typedef struct stack stack;

stack *stackCreate(void);
void stackDestroy(stack *s);

int stackPush(const stack *s, int value);
int stackPop(const stack *s);

int *stackTop(const stack *s);

size_t stackSize(const stack *s);
int stackEmpty(const stack *s);

#endif //STACK_H
