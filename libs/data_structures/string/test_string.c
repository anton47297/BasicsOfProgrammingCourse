#include "test_string.h"

void test_find() {
    char *str = "fh&shwuk2jj4";
    int lenghtStr = 7;
    char *res = str + lenghtStr;

    assert(find(str, str + lenghtStr, 'k') == res);
}

void test_findNonSpace() {
    char *str = "  6shwjw8";
    char *res = &str[2];

    assert(findNonSpace(str) == res);
}

void test_findSpace() {
    char *str = "ge272eh";
    char *res = &str[7];

    assert(findSpace(str) == res);
}

void test_findSpaceReverse() {
    char *str = "hsd 6e g";
    char *res = &str[6];
    int lenghtStr = 8;

    assert(findSpaceReverse(str + lenghtStr - 1, str) == res);
}

void test_findNonSpaceReverse() {
    char *str = "  \t  f";
    char *res = &str[5];
    int lenghtStr = 6;

    assert(findNonSpaceReverse(str + lenghtStr - 1, str) == res);
}

void test_strcmp() {
    char *str = "djwijan 83";
    char *res = "djwijan 83";

    assert(!strcmp(str, res));
}

void test_copy() {
    char *str = "lds3993";
    int lenghtStr = 7;

    char *endStr = "s39";

    char *resBegin = malloc(sizeof(char) * (lenghtStr + 1));

    char *resEnd = copy(&str[2], &str[5], resBegin); //"s39"
    *resEnd = '\0';

    assert(!strcmp(endStr, resBegin));

    free(resBegin);
}

int isDigit(int x) {
    return x >= '0' && x <= '9';
}

int isNotDigit(int x) {
    return !isDigit(x);
}

void test_copyIf() {
    char *str = "d34f 8xwj0q x";
    int lenghtStr = 13;

    char *endStr = "3480";

    char *resBegin = malloc(sizeof(char) * (lenghtStr + 1));

    char *resEnd = copyIf(str, str + lenghtStr, resBegin, isDigit);
    *resEnd = '\0';

    assert(!strcmp(endStr, resBegin));

    free(resBegin);
}

void test_copyIfReverse() {
    char *str = "je4 6 4c3flr";
    int lenghtStr = 12;

    char *endStr = "3464";

    char *resBegin = malloc(sizeof(char) * (lenghtStr + 1));

    char *resEnd = copyIfReverse(str + lenghtStr, str - 1, resBegin, isDigit);
    *resEnd = '\0';

    assert(!strcmp(endStr, resBegin));

    free(resBegin);
}

void test_str() {
    test_find();
    test_findNonSpace();
    test_findSpace();
    test_findNonSpaceReverse();
    test_findSpaceReverse();
    test_strcmp();
    test_copy();
    test_copyIf();
    test_copyIfReverse();
}