#include "sortings_array.h"

void bubbleSort(int *a, size_t n) {
    for (size_t i = 0; i < n - 1; i++)
        for (size_t j = n - 1; j > i; j--)
            if (a[j - 1] > a[j])
                swap(&a[j - 1], &a[j]);
}

void selectionSort(int *a, size_t n) {
    for (int i = 0; i < n - 1; i++) {
        int minPos = i;
        for (int j = i + 1; j < n; j++)
            if (a[j] < a[minPos])
                minPos = j;
        swap(&a[i], &a[minPos]);
    }
}

void insertionSort(int *a, const size_t n) {
    for (size_t i = 1; i < n; i++) {
        int t = a[i];
        size_t j = i;
        while (j > 0 && a[j - 1] > t) {
            a[j] = a[j - 1];
            j--;
        }
        a[j] = t;
    }
}

void combSort(int *a, const size_t n) {
    size_t step = n;
    int swapped = 1;
    while (step > 1 || swapped) {
        if (step > 1)
            step /= FACTOR;
        swapped = 0;
        for (size_t i = 0, j = i + step; j < n; ++i, ++j) {
            if (a[i] > a[j]) {
                universalSwap(&a[i], &a[j], sizeof(int));
                swapped = 1;
            }
        }
    }
}

void shellSort(int *a, size_t n) {
    for (size_t step = n / 2; step > 0; step /= 2)
        for (size_t i = step; i < n; i++) {
            size_t j;
            for (j = i; j >= step; j -= step) {
                if (a[i] < a[j - step])
                    a[j] = a[j - step];
            }
            a[j] = a[i];
        }
}

void radixSort_(int *l, int *r, int size) {
    int k = (32 + size - 1) / size;
    int M = 1 << size;
    int sz = r - l;
    int *b = (int *) malloc(sizeof(int) * sz);
    int *c = (int *) malloc(sizeof(int) * M);
    for (int i = 0; i < k; i++) {
        for (int j = 0; j < M; j++)
            c[j] = 0;

        for (int *j = l; j < r; j++)
            c[digit(*j, i, size, M)]++;

        for (int j = 1; j < M; j++)
            c[j] += c[j - 1];

        for (int *j = r - 1; j >= l; j--)
            b[--c[digit(*j, i, size, M)]] = *j;

        int cur = 0;
        for (int *j = l; j < r; j++)
            *j = b[cur++];
    }

    free(b);
    free(c);
}

void radixSort(int *a, size_t n) {
    radixSort_(a, a + n, 8);
}

/* --------------------------------------------------------------------------------------------
   -------------------------------------------------------------------------------------------- */

