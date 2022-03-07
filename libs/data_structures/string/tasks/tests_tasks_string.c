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

void test_removeNonLetters() {
    char str[] = "38r 3dbd f ";

    removeNonLetters(str);

    char res[] = "38r3dbdf";

    ASSERT_STRING(res, str);
}

void test_removeAdjacentEqualLetters() {
    char str[] = "ddgsiiwwwnx";

    removeAdjacentEqualLetters(str);

    char res[] = "dgsiwnx";

    ASSERT_STRING(res, str);
}

void test_removeExtraSpaces() {
    char str[] = "er    re fs   2 4  c";

    removeExtraSpaces(str);

    char res[] = "er re fs 2 4 c";

    ASSERT_STRING(res, str);
}

void test_digitRevers() {
    char str[] = "5gd389he ey63 eh38";

    digitRevers(str);

    char res[] = "gdhe9835 ey36 eh83";

    ASSERT_STRING(res, str);
}

void test_convertsStringByReplacingDigit() {
    char str[] = "2mme";

    convertsStringByReplacingDigit(str);

    char res[] = "  mme";

    ASSERT_STRING(res, str);
}

void test_tasks_string() {
    test_removeNonLetters();
    test_removeAdjacentEqualLetters();
    test_removeExtraSpaces();
    test_digitRevers();
    test_convertsStringByReplacingDigit();
}
