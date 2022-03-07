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

void movingDigitToEnd(WordDescriptor word) {
    char *endStringBuffer = copy(word.begin, word.end,
                                 _stringBuffer);
    char *recPosition = copyIf(_stringBuffer, endStringBuffer, word.begin, isalpha);

    copyIfReverse(endStringBuffer - 1,
                  _stringBuffer - 1,
                  recPosition, isdigit);
}

void digitRevers(char *str) {
    char *beginStr = str;
    WordDescriptor word;

    while (getWord(beginStr, &word)) {
        movingDigitToEnd(word);
        beginStr = word.end;
    }
}

// Task 4

void convertsStringByReplacingDigit(char *str) {
    char *endBuffer = copy(str, str + strlen_(str), _stringBuffer);
    char *beginBuffer = _stringBuffer;
    while (beginBuffer < endBuffer) {
        if (isdigit(*beginBuffer)) {
            int nSpaces = *beginBuffer - '0';
            for (int i = 0; i < nSpaces; ++i)
                *str++ = ' ';
        } else
            *str++ = *beginBuffer;

        beginBuffer++;
    }

    *str = '\0';
}

// Task 8

int isPalindromeWord(WordDescriptor word) {
    char *left = word.begin;
    char *right = word.end - 1;

    while (right - left > 0) {
        if (*left != *right)
            return 0;

        left++;
        right--;
    }

    return 1;
}

int getCountPalindromeWords(char *str) {
    WordDescriptor word;
    int count = 0;

    if (*str == '\0')
        return count;

    char *last = str;

    while (getWordSeparatedByComma(last, &word)) {
        if (isPalindromeWord(word))
            count++;
        last = word.end + 1;
    }
    return count;
}