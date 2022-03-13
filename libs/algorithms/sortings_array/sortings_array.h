#ifndef MAIN_C_SORTINGS_ARRAY_H
#define MAIN_C_SORTINGS_ARRAY_H

#include <stddef.h>
#include "../algorithms.h"

// сортировка обменом
// массива a размера n типа int
void bubbleSort(int *a, size_t n);

// сортировка вставками по неубыванию
// массива a размера n типа int.
void insertionSort(int *a, size_t n);

#endif//MAIN_C_SORTINGS_ARRAY_H
