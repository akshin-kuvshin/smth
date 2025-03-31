// author: Danila "akshin_" Axyonov

// Задача 4. Используя БМ-пoиск, определить,
// входит ли заданное слово в текст,
// если входит, вывести индекс начала вхождения.

#include <stdio.h>
#include <string.h>
#include <assert.h>
#include <iso646.h>
#include "boyer_moore.h"

const int MAX_INPUT_LEN = 1000;

int main() {
    char text[MAX_INPUT_LEN];
    printf("\nВведите текст:\n> ");
    gets(text);
    int text_len = strlen(text);

    char word[MAX_INPUT_LEN];
    printf("\nВведите искомое слово:\n> ");
    gets(word);
    int word_len = strlen(word);

    assert(word_len <= text_len and "Длина текста не может быть меньше длины искомого в нём слова");

    int shift[SHIFT_ARR_LEN];
    fill_shift_arr(shift, word, word_len);

    int ind = boyer_moore_search(text, text_len, word, word_len, shift);
    if (ind == NOT_FOUND)
        printf("\nВведённое Вами слово отсутствует во введённом Вами тексте.\n");
    else
        printf("\nВведённое Вами слово присутствует во введённом Вами тексте.\nИндекс начала вхождения = %d (нумерация с нуля).\n", ind);

    return 0;
}
