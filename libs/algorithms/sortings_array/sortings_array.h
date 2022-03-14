#ifndef MAIN_C_SORTINGS_ARRAY_H
#define MAIN_C_SORTINGS_ARRAY_H

#include <stdlib.h>
#include <stdbool.h>
#include <stddef.h>
#include "../../algorithms/array/array.h"
#include "../algorithms.h"
#include <memory.h>

#define FACTOR 1.24733

void bubbleSort(int *a, size_t n);

void selectionSort(int *a, size_t n);

void insertionSort(int *a, size_t n);

void combSort(int *a, size_t n);

void shellSort(int *a, size_t n);

void radixSort(int *a, size_t n);

#endif//MAIN_C_SORTINGS_ARRAY_H
