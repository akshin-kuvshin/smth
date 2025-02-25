#include <stdio.h>
#include <assert.h>
#include <iso646.h>
#include "BV.h"

BV string_to_BV(const char* S, int len) {
    BV V = 0ULL;
    for (int i = 0; i < len; ++i) {
        assert((S[i] == '0' or S[i] == '1') and "Введённые данные не могут быть сконвертированы в булев вектор!");
        
        V <<= 1;
        if (S[i] == '1')
            V |= 1ULL;
    }
    return V;
}

void print_BV(BV V, int n) {
    for (BV mask = (1ULL << (n - 1)); mask; mask >>= 1)
        printf("%c", ((V & mask) ? '1' : '0'));
    printf("\n");
    return;
}
