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

void test_getCountPalindromeWords() {
    char str[] = "f33f, rey423, hhhhhh, ui55iu";

    int res = 3;

    assert(getCountPalindromeWords(str) == res);

    printf("test_getCountPalindromeWords - OK\n");
}

void test_wordsOrdered() {
    char str[] = "anvfd jsfvj sklav";

    bool res = true;

    assert(wordOrdered(str) == res);

    printf("test_wordsOrdered - OK\n");
}

void test_identifyIdenticalWords() {
    char str[] = "cat dog camel";

    bool res = identifyIdenticalWords(str);

    assert(res == true);

    printf("test_allWordsAreUnique2 - OK\n");
}

void test_lastOfWordsOfFirstStringWhichIsInSecondString() {
    char str1[] = "";
    char str2[] = "last read qdca";

    WordDescriptor w;

    bool res = lastOfWordsOfFirstStringWhichIsInSecondString(str1, str2, &w);

    assert(false == res);

    printf("test_lastWordsOfTheStr1WhichIsInTheStr2_1 - OK\n");
}


void test_tasks_string() {
    test_removeNonLetters();
    test_removeAdjacentEqualLetters();
    test_removeExtraSpaces();
    test_digitRevers();
    test_convertsStringByReplacingDigit();
    test_getCountPalindromeWords();
    test_wordsOrdered();
    test_identifyIdenticalWords();
    test_lastOfWordsOfFirstStringWhichIsInSecondString();
}
