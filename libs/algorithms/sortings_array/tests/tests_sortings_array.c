#include "tests_sortings_array.h"

void checkTime(void (*sortFunc)(int *, size_t),
               void (*generateFunc)(int *, size_t),
               size_t size, char *experimentName) {
    static size_t runCounter = 1;

    int innerBuffer[100000];
    generateFunc(innerBuffer, size);
    printf(" Run #%zu| ", runCounter++);
    printf(" Name: %s\n", experimentName);

    double time;
    TIME_TEST({
        sortFunc(innerBuffer, size);
    }, time);

    printf("Status: ");
    if (isOrdered(innerBuffer, size)) {
        printf("OK! Time: %.3f\n", time);

        char filename[256];
        sprintf(filename, "./data/%s.csv", experimentName);
        FILE *f = fopen(filename, "a");
        if (NULL == f) {
            printf("FileOpenError %s", filename);
            exit(1);
        }
        fprintf(f, "%zu; %.3f\n", size, time);
        fclose(f);
    } else {
        printf("Wrong!\n");

        outputArray_(innerBuffer, size);

        exit(1);
    }
}

void timeExperiment() {
    SortFunc sorts[] = {
            {bubbleSort,    "bubbleSort"},
            {selectionSort, "selectionSort"},
            {insertionSort, "insertionSort"},
            {combSort,      "combSort"},
            {shellSort,     "shellSort"},
            {radixSort,     "radixSort"},
    };

    const unsigned FUNCS_N = ARRAY_SIZE(sorts);

    GeneratingFunc generating[] = {
            {generateRandomArray,      "random"},
            {generateOrderedArray,     "ordered"},
            {generateOrderedBackwards, "orderedBackwards"},
    };

    const unsigned CASES_N = ARRAY_SIZE(generating);

    for (size_t size = 10000; size <= 100000; size += 10000) {
        printf("----------------------------\n");
        printf("Size: %d\n", size);

        for (int i = 0; i < FUNCS_N; i++) {
            for (int j = 0; j < CASES_N; j++) {
                static char filename[128];
                sprintf(filename, "%s_%s_time",
                        sorts[i].name, generating[j].name);
                checkTime(sorts[i].sort,
                          generating[j].generate,
                          size,
                          filename);
            }
        }

        printf("\n");
    }
}