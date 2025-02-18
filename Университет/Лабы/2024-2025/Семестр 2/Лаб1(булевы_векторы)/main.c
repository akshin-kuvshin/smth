// Задача 22.
// Зеркально отобразить тетрады битов булева вектора.
// Например: 1101 0010 0000 1111 ==> 1111 0000 0010 1101.

// author: Danila "akshin_" Axyonov

#include <stdio.h>
#include <stdbool.h>
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
    if (len % 4)
        len = len - len % 4 + 4;
    int sections_amount = len / 4;

    printf("Было:\t");
    print_BV_sep4(V, len);

    BV W = V;
    for (int section_a = 0; section_a < sections_amount / 2; ++section_a) {
        int section_b = sections_amount - 1 - section_a;
        for (int inner_ind = 0; inner_ind < 4; ++inner_ind) {
            bool bit_a = (bool)(W & (1ULL << (section_a * 4 + inner_ind))),
                 bit_b = (bool)(W & (1ULL << (section_b * 4 + inner_ind)));
            if (bit_a != bit_b) {
                W ^= (1ULL << (section_a * 4 + inner_ind));
                W ^= (1ULL << (section_b * 4 + inner_ind));
            }
        }
    }

    printf("Стало:\t");
    print_BV_sep4(W, len);

    return 0;
}
