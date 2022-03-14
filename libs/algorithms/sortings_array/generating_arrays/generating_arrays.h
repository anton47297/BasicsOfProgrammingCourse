#ifndef MAIN_C_GENERATING_ARRAYS_H
#define MAIN_C_GENERATING_ARRAYS_H

#include <stdlib.h>
#include <time.h>
#include <limits.h>

// генерирует массив a размера n типа int со
// случайными значениями.
void generateRandomArray(int *a, size_t n);

// генерирует упорядоченный массив a размера n
void generateOrderedArray(int *a, size_t n);

// генерирует упорядоченный массив a размера n
void generateOrderedBackwards(int *a, size_t n);

#endif//MAIN_C_GENERATING_ARRAYS_H
