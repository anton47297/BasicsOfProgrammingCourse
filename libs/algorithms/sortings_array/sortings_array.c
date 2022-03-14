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

unsigned long long getBubbleSortNComps(int *a, const size_t n) {
    unsigned long long nComps = 0;
    for (int i = 0; ++nComps && i < n; ++i)
        for (int j = i; ++nComps && j < n; ++j)
            if (++nComps && a[i] > a[j])
                swap(&a[i], &a[j]);

    return nComps;
}

unsigned long long getSelectionSortNComps(int *a, size_t n) {
    unsigned long long nComps = 0;
    for (int i = 0; ++nComps && i < n; i++) {
        int min = a[i];
        int minIndex = i;
        for (int j = i + 1; ++nComps && j < n; j++)
            if (++nComps && a[j] < min) {
                min = a[j];
                minIndex = j;
            }
        if (++nComps && i != minIndex)
            swap(&a[i], &a[minIndex]);
    }

    return nComps;
}


unsigned long long getInsertionSortNComps(int *a, const size_t n) {
    unsigned long long nComps = 0;
    for (size_t i = 1; ++nComps && i < n; i++) {
        int t = a[i];
        int j = i;
        while (++nComps && j > 0 && a[j - 1] > t) {
            a[j] = a[j - 1];
            j--;
        }
        a[j] = t;
    }
    return nComps;
}


unsigned long long getCombSortNComps(int *a, const size_t n) {
    size_t step = n;
    int swapped = 1;
    unsigned long long nComps = 2;
    while (++nComps && step > 1 || swapped) {
        if (++nComps && step > 1)
            step /= FACTOR;
        swapped = 0;
        for (size_t i = 0, j = i + step; ++nComps && j < n; ++i, ++j)
            if (++nComps && a[i] > a[j]) {
                swap(&a[i], &a[j]);
                swapped = 1;
            }
    }
    return nComps;
}


unsigned long long getShellSortNComps(int *a, const size_t n) {
    unsigned long long nComps = 0;
    for (size_t step = n / 2; ++nComps && step > 0; step /= 2)
        for (size_t i = step; ++nComps && i < n; i++) {
            size_t j;
            for (j = i; ++nComps && j >= step; j -= step) {
                if (++nComps && a[i] < a[j - step])
                    a[j] = a[j - step];
            }
            a[j] = a[i];
        }
    return nComps;
}

unsigned long long getRadixSortNComps(int *a, const size_t n) {
    int N = 8;
    int *l = a;
    int *r = a + n;
    int k = (32 + N - 1) / N;
    int M = 1 << N;
    int sz = r - l;
    int *b = (int *) malloc(sizeof(int) * sz);
    int *c = (int *) malloc(sizeof(int) * M);
    unsigned long long nComps = 8;
    for (int i = 0; ++nComps && i < k; i++) {
        for (int j = 0; ++nComps && j < M; j++)
            c[j] = 0;

        for (int *j = l; ++nComps && j < r; j++)
            c[digit(*j, i, N, M)]++;

        for (int j = 1; ++nComps && j < M; j++)
            c[j] += c[j - 1];

        for (int *j = r - 1; ++nComps && j >= l; j--)
            b[--c[digit(*j, i, N, M)]] = *j;

        int cur = 0;
        ++nComps;
        for (int *j = l; ++nComps && j < r; j++)
            *j = b[cur++];
    }
    free(b);
    free(c);

    return nComps + 2;
}

