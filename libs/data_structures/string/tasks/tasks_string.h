#ifndef MAIN_C_TASKS_STRING_H
#define MAIN_C_TASKS_STRING_H

#include "../../string/string_.h"

void removeNonLetters(char *s);

// Преобразовывает строку,
// оставляя только один символ в каждой последовательности
// подряд идущих одинаковых символов
void removeAdjacentEqualLetters(char *s);

// Сокращает количество пробелов
// между словами данного предложения до одного
void removeExtraSpaces(char *s);

// перенести цифры в конец слова
void movingDigitToEnd(WordDescriptor word);

// Преобразовать строку таким образом, чтобы цифры каждого слова были
// перенесены в конец слова, и изменить порядок следования цифр в слове
// на обратный, буквы перенести в начало слова
void digitRevers(char *str);

// Преобразовывает строку,
// заменяя каждую цифру соответствующим ей числом пробелов
void convertsStringByReplacingDigit(char *str);

bool wordOrdered(char *str);

//возвращает 1 если слово является палиндромом, иначе 0
bool isPalindromeWord(WordDescriptor word);

//В данной строке соседние слова разделены запятыми. Определить количество
//слов-палиндромов
int getCountPalindromeWords(char *str);

#endif//MAIN_C_TASKS_STRING_H
