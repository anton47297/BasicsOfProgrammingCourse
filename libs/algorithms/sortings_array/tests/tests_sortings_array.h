#ifndef MAIN_C_TESTS_SORTINGS_ARRAY_H
#define MAIN_C_TESTS_SORTINGS_ARRAY_H

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "../../array/array.h"
#include "../sortings_array.h"
#include "../generating_arrays/generating_arrays.h"

#define TIME_TEST(testCode, time) { \
    clock_t startTime = clock(); \
    testCode \
    clock_t endTime = clock(); \
    clock_t sortingTime = endTime - startTime; \
    time = (double) sortingTime / CLOCKS_PER_SEC; \
}

#define ARRAY_SIZE(a) sizeof(a) / sizeof(a[0])

// функция сортировки
typedef struct SortFunc {
    void (*sort)(int *a, size_t n);// указатель на функцию
                                   // сортировки
    char name[64];                 // имя сортировки,
                                   // используемое при выводе
} SortFunc;

// функция генерации
typedef struct GeneratingFunc {
    void (*generate)(int *a, size_t n);// указатель на функцию
                                       // генерации последовательности.
    char name[64];                     // имя генератора,
                                       // используемое при выводе
} GeneratingFunc;

void checkTime(void (*sortFunc)(int *, size_t),
               void (*generateFunc)(int *, size_t),
               size_t size, char *experimentName);

void timeExperiment();

#endif//MAIN_C_TESTS_SORTINGS_ARRAY_H
