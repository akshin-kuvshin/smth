#include <stdio.h>
#include <assert.h>
#include <iso646.h>
#include "BV.h"

BV string_to_BV(const char* S, int len) {
    BV V = 0ULL;
    for (int i = 0; i < len; ++i) {
        assert((S[i] == '0' or S[i] == '1') and "Введённые данные не могут быть сконвертированы в булев вектор!");
        
        if (S[i] == '1')
            V |= 1ULL;
        if (i != len - 1)
            V <<= 1;
    }
    return V;
}

void print_BV_seg(BV V, int left, int right) {
    while (left >= right) {
        printf("%c", (V & (1ULL << left)) ? '1' : '0');
        --left;
    }
    return;
}
