#include "sortings_array.h"

void bubbleSort(int *const a, const size_t n) {
    for (size_t q = 0; q < n - 1; q++)
        for (size_t i = 0, j = 1; j < n - q; i++, j++)
            if (a[i] > a[j])
                universalSwap(&a[i], &a[j], sizeof(int));
}
