#include "test_string.h"

void test_find1() {
    char *str = "fh&shwuk2jj4";
    int lenghtStr = 7;
    char *res = str + lenghtStr;

    assert(find(str, str + lenghtStr, 'k') == res);
}

void test_find2() {
    char *str = "sdguuns46edn37";
    int lenghtStr = 14;
    char *res = &str[3];

    assert(find(str, str + lenghtStr, 'u') == res);
}

void test_find() {
    test_find1();
    test_find2();
}

void test_findNonSpace1() {
    char *str = "  6shwjw8";
    char *res = &str[2];

    assert(findNonSpace(str) == res);
}

void test_findNonSpace2() {
    char *str = "   ";
    char *res = &str[3];

    assert(findNonSpace(str) == res);
}

void test_findNonSpace() {
    test_findNonSpace1();
    test_findNonSpace2();
}


void test_findSpace1() {
    char *str = "ge272eh";
    char *res = &str[7];

    assert(findSpace(str) == res);
}

void test_findSpace2() {
    char *str = "gyf g43 4t";
    char *res = &str[3];

    assert(findSpace(str) == res);
}

void test_findSpace() {
    test_findSpace1();
    test_findSpace2();
}

void test_findSpaceReverse1() {
    char *str = "hsd 6e g";
    char *res = &str[6];
    int lenghtStr = 8;

    assert(findSpaceReverse(str + lenghtStr - 1, str) == res);
}

void test_findSpaceReverse2() {
    char *str = "idh234xs";
    char *res = str;
    int lenghtStr = 8;

    assert(findSpaceReverse(str + lenghtStr - 1, str) == res);
}

void test_findSpaceReverse() {
    test_findSpaceReverse1();
    test_findSpaceReverse2();
}

void test_findNonSpaceReverse1() {
    char *str = "  \t  f";
    char *res = &str[5];
    int lenghtStr = 6;

    assert(findNonSpaceReverse(str + lenghtStr - 1, str) == res);
}

void test_findNonSpaceReverse2() {
    char *str = "   ";
    char *res = str;
    int lenghtStr = 3;

    assert(findNonSpaceReverse(str + lenghtStr - 1, str) == res);
}

void test_findNonSpaceReverse() {
    test_findNonSpaceReverse1();
    test_findNonSpaceReverse2();
}

void test_strcmp1() {
    char *str = "djwijan 83";
    char *res = "djwijan 83";

    assert(!strcmp(str, res));
}

void test_strcmp2() {
    char *str = "djwn 83";
    char *res = "djwijan 83";

    assert(strcmp(str, res));
}

void test_strcmp() {
    test_strcmp1();
    test_strcmp2();
}

void test_copy1() {
    char *str = "lds3993";
    int lenghtStr = 7;

    char *endStr = "s39";

    char *resBegin = malloc(sizeof(char) * (lenghtStr + 1));

    char *resEnd = copy(&str[2], &str[5], resBegin); //"s39"
    *resEnd = '\0';

    assert(!strcmp(endStr, resBegin));

    free(resBegin);
}

void test_copy2() {
    char *str = "lds3993";
    int lenghtStr = 7;

    char *resBegin = malloc(sizeof(char) * (lenghtStr + 1));     //"s39"

    char *resEnd = copy(str, str + lenghtStr, resBegin);
    *resEnd = '\0';

    assert(!strcmp(str, resBegin));

    free(resBegin);
}

void test_copy() {
    test_copy1();
    test_copy2();
}

int isDigit(int x) {
    return x >= '0' && x <= '9';
}

int isNotDigit(int x) {
    return !isDigit(x);
}

void test_copyIf1() {
    char *str = "d34f 8xwj0q x";
    int lenghtStr = 13;

    char *endStr = "3480";

    char *resBegin = malloc(sizeof(char) * (lenghtStr + 1));

    char *resEnd = copyIf(str, str + lenghtStr, resBegin, isDigit);
    *resEnd = '\0';

    assert(!strcmp(endStr, resBegin));

    free(resBegin);
}

void test_copyIf2() {
    char *str = "d34f 8xwj0q x";
    int lenghtStr = 13;

    char *endStr = "df xwjq x";

    char *resBegin = malloc(sizeof(char) * (lenghtStr + 1));

    char *resEnd = copyIf(str, str + lenghtStr, resBegin, isNotDigit);
    *resEnd = '\0';

    assert(!strcmp(endStr, resBegin));

    free(resBegin);
}

void test_copyIf() {
    test_copyIf1();
    test_copyIf2();
}

void test_copyIfReverse1() {
    char *str = "je4 6 4c3flr";
    int lenghtStr = 12;

    char *endStr = "3464";

    char *resBegin = malloc(sizeof(char) * (lenghtStr + 1));

    char *resEnd = copyIfReverse(str + lenghtStr, str - 1, resBegin, isDigit);
    *resEnd = '\0';

    assert(!strcmp(endStr, resBegin));

    free(resBegin);
}

void test_copyIfReverse2() {
    char *str = "je4 6 4c3flr";
    int lenghtStr = 11;

    char *endStr = "rlfc  e";

    char *resBegin = malloc(sizeof(char) * (lenghtStr + 1));

    char *resEnd = copyIfReverse(str + lenghtStr , str, resBegin, isNotDigit);
    *resEnd = '\0';

    assert(!strcmp(endStr, resBegin));

    free(resBegin);
}

void test_copyIfReverse() {
    test_copyIfReverse1();
    test_copyIfReverse2();
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