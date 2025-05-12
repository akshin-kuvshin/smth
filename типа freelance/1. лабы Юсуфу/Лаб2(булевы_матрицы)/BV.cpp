// author: Danila "akshin_" Axyonov

#include <cstdio>
#include "BV.h"

BV StringToBV(const char* S, int n) {
    BV r = 0;
    for (int i = 0; i < n; ++i) {
        r <<= 1; // дописываем справа ноль
        if (S[i] == '1')
            r |= 1; // по необходимости меняем новый ноль на единицу
    }
    return r;
}

void OutPutBV(BV r, int n) {
    for (int i = n - 1; i >= 0; --i) {
        BV mask = (1 << i);
        BV res = r & mask;
        
        // if (res != 0)
        //     printf("1");
        // else // res == 0
        //     printf("0");
        
        // через тернарный оператор:
        printf("%d", res != 0 ? 1 : 0);
    }
    printf("\n");
    return;
}
