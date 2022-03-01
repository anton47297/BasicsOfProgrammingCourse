#include "tests_tasks_string.h"

#define ASSERT_STRING(expected, got) assertString(expected, got, \
                                                  __FILE__, __FUNCTION__, __LINE__)

void assertString(const char *expected, char *got,
                  char const *fileName, char const *funcName,
                  int line) {
    if (strcmp(expected, got) != 0) {
        fprintf(stderr, " File %s\n", fileName);
        fprintf(stderr, "%s - failed on line %d\n", funcName, line);
        fprintf(stderr, " Expected : \"%s\"\n", expected);
        fprintf(stderr, "Got: \"%s\"\n\n", got);
    } else
        fprintf(stderr, "%s - OK\n", funcName);
}

void test_removeNonLetters1() {
    char str[] = "38r 3dbd f ";

    removeNonLetters(str);

    char res[] = "38r3dbdf";

    ASSERT_STRING(res, str);
}

void test_removeNonLetters2() {
    char str[] = "    ";

    removeNonLetters(str);

    char res[] = "";

    ASSERT_STRING(res, str);
}

void test_removeNonLetters() {
    test_removeNonLetters1();
    test_removeNonLetters2();
}

void test_removeAdjacentEqualLetters1() {
    char str[] = "ddgsiiwwwnx";

    removeAdjacentEqualLetters(str);

    char res[] = "dgsiwnx";

    ASSERT_STRING(res, str);
}

void test_removeAdjacentEqualLetters2() {
    char str[] = "h1gwwbwigw1";

    removeAdjacentEqualLetters(str);

    char res[] = "h1gwbwigw1";

    ASSERT_STRING(res, str);
}

void test_removeAdjacentEqualLetters() {
    test_removeAdjacentEqualLetters1();
    test_removeAdjacentEqualLetters2();
}

void test_removeExtraSpaces1() {
    char str[] = "er    re fs   2 4  c";

    removeExtraSpaces(str);

    char res[] = "er re fs 2 4 c";

    ASSERT_STRING(res, str);
}

void test_removeExtraSpaces2() {
    char str[] = "  fef     fewwd uy     pop";

    removeExtraSpaces(str);

    char res[] = " fef fewwd uy pop";

    ASSERT_STRING(res, str);
}

void test_removeExtraSpaces() {
    test_removeExtraSpaces1();
    test_removeExtraSpaces2();
}


void test_digitRevers1() {
    char str[] = "5gd389he ey63 eh38";

    digitRevers(str);

    char res[] = "gdhe9835 ey36 eh83";

    ASSERT_STRING(res, str);
}

void test_digitRevers2() {
    char str[] = "78hdy 7750 6c74clsls";

    digitRevers(str);

    char res[] = "hdy87 0577 cclsls476";

    ASSERT_STRING(res, str);
}

void test_digitRevers() {
    test_digitRevers1();
    test_digitRevers2();
}

void test_tasks_string() {
    test_removeNonLetters();
    test_removeAdjacentEqualLetters();
    test_removeExtraSpaces();
    test_digitRevers();
}
