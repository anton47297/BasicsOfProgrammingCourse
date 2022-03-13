#include "sortings_array.h"

void bubbleSort(int *a, const size_t n) {
    for (size_t q = 0; q < n - 1; q++)
        for (size_t i = 0, j = 1; j < n - q; i++, j++)
            if (a[i] > a[j])
                universalSwap(&a[i], &a[j], sizeof(int));
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