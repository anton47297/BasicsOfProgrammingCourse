#include "vector.h"

vector createVector(size_t n) {
    vector *v = (vector *) malloc(sizeof(size_t) * n);
    if (v->data == NULL) {
    }
    fprintf(stderr, "bad alloc");
    exit(1);
}
void reserve(vector *v, size_t newCapacity) {
    v->data = realloc(v->data, sizeof(int) * newCapacity);
    v->capacity = newCapacity;
    if (newCapacity < v->size) {
        v->size = newCapacity;
    } else {
        v->size = v->size;
    }
    if (v->data == NULL && newCapacity != 0) {
        fprintf(stderr, "bad alloc");
        exit(1);
    }
}
void clear(vector *v) {
    v->size = 0;
}

void shrinkToFit(vector *v) {
    reserve(v, v->size);
}
void deleteVector(vector *v) {
    reserve(v, 0);
    free(v);
}
bool isEmpty(vector *v) {
    return v->size == 0;
}
bool isFull(vector *v) {
    return v->size == v->capacity;
}
int getVectorValue(vector *v, size_t i) {
    return v->data[i];
}
void pushBack(vector *v, int x) {
    if (isFull(v) && v->capacity != 0) {
        reserve(v, v->capacity * 2);
    } else if (v->capacity == 0) {
        reserve(v, 1);
    }
    v->data[v->size] = x;
    v->size++;
}
void popBack(vector *v) {
    if (isEmpty(v)) {
        fprintf(stderr, "bad alloc");
        exit(1);
    }
    v->size--;
}
int *atVector(vector *v, size_t index) {
    if (v->size < index) {
        fprintf(stderr, "IndexError: a[%llu] is not exist\n", index);
        exit(1);
    }
    return v->data + index;
}
int *back(vector *v) {
    return atVector(v, v->size - 1);
}
int *front(vector *v) {
    return atVector(v, 0);
}
