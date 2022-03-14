//
// Created by Антон on 26.02.2022.
//

#include "algorithms.h"
#include <stdlib.h>

void universalSwap(void *a, void *b, const size_t size) {
    char *a1 = a;
    char *b1 = b;
    for (int i = 0; i < size; i++) {
        char t = *a1;
        *a1 = *b1;
        *b1 = t;
        a1++;
        b1++;
    }
}

int digit(int n, int k, int N, int M) {
    return (n >> (N * k) & (M - 1));
}
