// Задача 22.
// Зеркально отобразить тетрады битов булева вектора.
// Например: 1101 0010 0000 1111 ==> 1111 0000 0010 1101.

// author: Danila "akshin_" Axyonov

#include <stdio.h>
#include <string.h>
#include <assert.h>
#include <iso646.h>
#include "BV.h"

const int MAX_INPUT_LEN = 1000;

int main() {
    char input[MAX_INPUT_LEN];
    printf("Введите булев вектор в виде последовательности 1 и 0 (длиной не более 64):\n> ");
    gets(input);
    int len = (int)strlen(input);
    assert(len <= MAX_BV_LEN and "Введённый Вами вектор превышает ограничение по размеру в 64 элемента!");

    BV V = string_to_BV(input, len);

    // Так или иначе, рассматриваем тетрады битов только целиком.
    // При необходимости дополняем булев вектор ведущими нулями.
    int sections_amount = (len + 3) / 4;

    // Было
    printf("Было:\t");
    for (int section = sections_amount - 1; section >= 0; --section) {
        print_BV_seg(V, section * 4 + 3, section * 4);
        printf(" ");
    }
    printf("\n");

    // Стало
    printf("Стало:\t");
    for (int section = 0; section < sections_amount; ++section) {
        print_BV_seg(V, section * 4 + 3, section * 4);
        printf(" ");
    }
    printf("\n");

    return 0;
}
