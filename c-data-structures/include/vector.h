#ifndef VECTOR_H
#define VECTOR_H

#include <stdint.h>

typedef struct {
    int *data;
    size_t size;
    size_t capacity;
}vector;

vector *vectorCreate(void);
void vectorDestroy(vector *v);

int *vectorFront(const vector *l);
int *vectorBack(const vector *l);
int *vectorGet(const vector *v, size_t index);
int vectorSet(const vector *v, size_t index, int value);

int vectorPushBack(vector *v, int value);
int vectorPopBack(vector *v);
void vectorClear(vector *v);

size_t vectorSize(const vector *v);
int vectorEmpty(const vector *v);
int vectorReserve(vector *v, size_t newCapacity);

#endif //VECTOR_H
