//
// Created by Антон on 26.02.2022.
//

#ifndef LAB_MATRIX_H
#define LAB_MATRIX_H

#include <malloc.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <assert.h>
#include <memory.h>
#include <math.h>
#include <limits.h>
#include <stddef.h>

void universalSwap(void *x, void *y, const size_t n) {
    char *a= x;
    char *b = y;
    for (size_t i = 0; i < n; i++) {
        char t = *a;
        *a = *b;
        *b = t;
        a++;
        b++;
    }
}

int maxArray(int *a, int size) {
    int max = a[0];
    for (size_t i = 1; i < size; i++) {
        if (a[i] > max) {
            max = a[i];
        }
    }
    return max;
}

typedef struct matrix {
    int **values;// элементы матрицы
    int nRows;   // количество рядов
    int nCols;   // количество столбцов
} matrix;

typedef struct position {
    int rowIndex;
    int colIndex;
} position;

// размещает в динамической памяти матрицу размером nRows на nRows
// возвращает матрицу
matrix getMemMatrix(int nRows, int nCols);

// размещает в динамической памяти массив из nMatrices матриц размером nRows на nRows
// возвращает указатель на нулевую матрицу.
matrix *getMemArrayOfMatrices(int nMatrices, int nRows, int nCols);

// освобождает память, выделенную под
// хранение матрицы m
void freeMemMatrix(matrix m);

// освобождает память, выделенную под хранение массива ms из nMatrices матриц
void freeMemMatrices(matrix *ms, int nMatrices);

// ввод матрицы m
void inputMatrix(matrix *m);

// ввод массива из
// nMatrices матриц, хранящейся по адресу ms.
void inputMatrices(matrix *ms, int nMatrices);

// вывод матрицы m
void outputMatrix(matrix m);

// вывод массива из nMatrices матриц, хранящейся по адресу ms
void outputMatrices(matrix *ms, int nMatrices);

// обмен строк с порядковыми
// номерами i1 и i2 в матрице m
void swapRows(matrix m, int i1, int i2);

// обмен колонок с порядковыми номерами j1 и j2 в матрице m
void swapColumns(matrix m, int j1, int j2);

// выполняет сортировку вставками строк
// матрицы m по не убыванию значения функции criteria
// применяемой для строк
void insertionSortRowsMatrixByRowCriteria(matrix m, int (*criteria)(int *, int));

// выполняет сортировку вставками
// столбцов матрицы m по не убыванию значения функции criteria
// применяемой для столбцов
void insertionSortColsMatrixByColCriteria(matrix m, int (*criteria)(int *, int));

// возвращает значение ’истина’, если
// матрица m является квадратной, ложь – в противном случае
bool isSquareMatrix(matrix m);

// возвращает значение
// ’истина’, если матрицы m1 и m2 равны, ложь – в противном случае.
bool areTwoMatricesEqual(matrix m1, matrix m2);

// возвращает значение ’истина’, если матрица
// m является единичной, ложь – в противном случае
bool isEMatrix(matrix m);

// возвращает значение ’истина’, если
// матрица m является симметричной, ложь – в противном случае
bool isSymmetricMatrix(matrix m);

// транспонирует квадратную матрицу m
void transposeSquareMatrix(matrix m);

// возвращает позицию минимального элемента матрицы m
position getMinValuePos(matrix m);

// возвращает позицию максимального элемента матрицы m
position getMaxValuePos(matrix m);

// возвращает матрицу, размера nRows на nRows,
// построенного из элементов массива a, размещенную в динамической
// памяти
matrix createMatrixFromArray(const int *a, size_t nRows, size_t nCols);

// возвращает указатель на нулевую матрицу массива из nMatrices матриц, размещенных
// в динамической памяти, построенных из элементов массива a
matrix *createArrayOfMatrixFromArray(const int *values, size_t nMatrices, size_t nRows, size_t nCols);

#endif//LAB_MATRIX_H
