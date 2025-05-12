// author: Danila "akshin_" Axyonov

// Задание 19.

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "lib.h"

const int MAX_SIZE = 32;

int main()
{
    srand(time(NULL)); // для того, чтобы рандомные числа не повторялись

    int a[MAX_SIZE];

    int n, i;
    printf("n = ");
    scanf("%d", &n);
    if (n > 32) {
        printf("too much\n");
        return 0;
    }

    RandMasAny(a, n);
    OutPutMas(a, n);

    UI r = 0;
    
    for (i = 0; i < n; i++)
    {
        if(a[i] % 3 == 0)
        {
            UI mask = (1 << (n - i - 1));
            r |= mask;
        }
    }
    OutPutUI(r, n);

    return 0;
}
