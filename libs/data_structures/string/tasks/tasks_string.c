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

// Task 6

bool wordOrdered(char *str) {
    WordDescriptor w1;
    WordDescriptor w2;

    if (!getWord(str, &w1))
        return true;

    while (getWord(str, &w2)) {
        if (!areWordsEqual(w1, w2) && strcmp(w1.begin, w2.begin) > 0)
            return false;

        w1 = w2;
        str = w2.end;
    }

    return true;
}

// Task 7

void printWord(WordDescriptor w) {
    char *endBuffer = copy(w.begin, w.end, _stringBuffer);

    *endBuffer = '\0';

    printf("%s", _stringBuffer);
}

void printRevers(char *str) {
    BagOfWords w;
    getBagOfWords(&w, str);

    for (int i = w.size - 1; i >= 0; --i) {
        printWord(w.words[i]);
        printf("\n");
    }
}

// Task 8

bool isPalindromeWord(WordDescriptor word) {
    char *left = word.begin;
    char *right = word.end - 1;

    while (right - left > 0) {
        if (*left != *right)
            return false;

        left++;
        right--;
    }

    return true;
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

// Task 9

void getStringWithMixWords(char *str1, char *str2, char *res) {
    WordDescriptor word1, word2;
    bool isW1Found, isW2Found;
    char *beginSearch1 = str1, *beginSearch2 = str2;

    while ((isW1Found = getWord(beginSearch1, &word1)),
           (isW2Found = getWord(beginSearch2, &word2)),
           isW1Found || isW2Found) {

        if (isW1Found) {
            res = copy(word1.begin, word1.end, res);
            beginSearch1 = word1.end;
            *res = ' ';
            res++;
        }

        if (isW2Found) {
            res = copy(word2.begin, word2.end, res);
            beginSearch2 = word2.end;
            *res = ' ';
            res++;
        }
    }

    *(res - 1) = '\0';
}

// Task 12

bool lastOfWordsOfFirstStringWhichIsInSecondString(char *str1, char *str2, WordDescriptor *w) {

    if (*str1 == '\0' && *str2 == '\0')
        return false;

    getBagOfWords(&_bag, str2);

    WordDescriptor *_bagEnd = _bag.size + _bag.words;
    char *endStr1 = getEndOfString(str1);

    WordDescriptor lastWord;
    while (getWordRevers(endStr1 - 1, str1 - 1, &lastWord)) {
        for (WordDescriptor *curWord = _bag.words; curWord < _bagEnd; curWord++) {
            if (areWordsEqual(lastWord, *curWord)) {
                *w = lastWord;
                return true;
            }
        }
        endStr1 = lastWord.begin;
    }

    return false;
}

// Task 13

bool identifyIdenticalWords(char *str) {
    getBagOfWords(&_bag, str);

    WordDescriptor *curWord = _bag.words;
    WordDescriptor *endWord = _bag.words + _bag.size - 1;

    while (endWord > curWord) {
        WordDescriptor *w = curWord + 1;
        while (endWord >= w) {
            if (areWordsEqual(*curWord, *w))
                return false;
            w++;
        }
        curWord++;
    }

    return true;
}