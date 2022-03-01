#include "tasks_string.h"

// Task 1
void removeNonLetters(char *s) {
    char *endSource = getEndOfString(s);
    char *destination = copyIf(s, endSource, s, isgraph);
    *destination = '\0';
}

// Task 2
void removeAdjacentEqualLetters(char *s) {
    if (*s == '\0')
        return;

    char *lastWriten = s;
    s++;

    while (*s) {
        if (*lastWriten != *s) {
            lastWriten++;
            memcpy(lastWriten, s, sizeof(char));
        }
        s++;
    }
    lastWriten++;
    *lastWriten = '\0';
}

void removeExtraSpaces(char *s) {
    if (*s == '\0')
        return;

    char *lastWriten = s;
    s++;

    while (*s) {
        if (isspace(*lastWriten) && isspace(*s)) {
            *lastWriten = ' ';
        } else {
            lastWriten++;
            memcpy(lastWriten, s, sizeof(char));
        }
        s++;
    }
    lastWriten++;
    *lastWriten = '\0';
}

// Task 3
