#include "vector.h"
#include <stdlib.h>

#define VECTOR_INITIAL_CAPACITY 16

vector *vectorCreate() {
    vector *v = malloc(sizeof(vector));
    if (!v) return NULL;

    v->data = malloc(sizeof(int) * VECTOR_INITIAL_CAPACITY);
    if (!v->data) {
        free(v);
        return NULL;
    }

    v->size = 0;
    v->capacity = VECTOR_INITIAL_CAPACITY;
    return v;
}

void vectorDestroy(vector *v) {
    free(v->data);
    free(v);
}

int *vectorFront(const vector *l) {
    return l->size > 0 ? &l->data[0] : NULL;
}

int *vectorBack(const vector *l) {
    return l->size > 0 ? &l->data[l->size - 1] : NULL;
}

int *vectorGet(const vector *v, const size_t index) {
    if(index >= v->size) return NULL;
    return &v->data[index];
}

int vectorSet(const vector *v, const size_t index, const int value) {
    if(index >= v->size) return 0;
    v->data[index] = value;
    return 1;
}

static int vectorResize(vector *v, const size_t newCapacity) {
    int *new_data = realloc(v->data, sizeof(int) * newCapacity);
    if (!new_data && newCapacity > 0) return 0;
    v->data = new_data;
    v->capacity = newCapacity;
    return 1;
}

int vectorPushBack(vector *v, const int value) {
    if (v->size == v->capacity) {
        const size_t newCapacity = v->capacity == 0 ? 1 : v->capacity * 2;
        if (!vectorResize(v, newCapacity)) return 0;
    }
    v->data[v->size++] = value;
    return 1;
}

int vectorPopBack(vector *v) {
    if (v->size == 0) return 0;
    v->size--;
    return 1;
}

void vectorClear(vector *v) {
    v->size = 0;
}

size_t vectorSize(const vector *v) {
    return v->size;
}

int vectorEmpty(const vector *v) {
    return v->size == 0;
}

int vectorReserve(vector *v, const size_t newCapacity) {
    if (newCapacity <= v->capacity) return 1;
    return vectorResize(v, newCapacity);
}