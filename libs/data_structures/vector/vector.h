#ifndef LAB_VECTOR_H
#define LAB_VECTOR_H

#include <stdio.h>
#include <malloc.h>
#include <stdbool.h>
#include <stdint.h>
#include <stdlib.h>

typedef struct vector {
    int *data; // указатель на элементы вектора
    size_t size; // размер вектора
    size_t capacity;// вместимость вектора
} vector;

// возвращает структуру-дескриптор вектор из n значений
vector createVector(size_t n);

// изменяет количество памяти,
// выделенное под хранение элементов вектора
void reserve(vector *v, size_t newCapacity);

// удаляет элементы из контейнера,
// но не освобождает выделенную память
void clear(vector *v);

// освобождает память, выделенную под
// неиспользуемые элементы
void shrinkToFit(vector *v);

// освобождает память, выделенную вектору
void deleteVector(vector *v);

//Возвращает i-ый элемент вектора v.
int getVectorValue(vector *v, size_t i);

//Добавляет элемент x в конец вектора v.
void pushBack(vector *v, int x);

//Проверка вектора на пустоту.
bool isEmpty(vector *v);

//Проверка вектора на полноту.
bool isFull(vector *v);

//Удаляет последний элемент из вектора.
void popBack(vector *v);

//Возвращает указатель на index-ый элемент вектора.
int *atVector(vector *v, size_t index);

//Возвращает указатель на последний элемент вектора.
int *back(vector *v);

//Возвращает указатель на первый элемент вектора.
int *front(vector *v);

#endif//LAB_VECTOR_H
