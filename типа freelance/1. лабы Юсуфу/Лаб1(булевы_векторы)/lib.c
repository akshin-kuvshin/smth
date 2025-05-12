// author: Danila "akshin_" Axyonov

#include "lib.h"

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void RandMasAny(int a[], int n)
{
    for(int i = 0; i<n; i++)
    {
        a[i] = rand()%100-1;
    }
}
void OutPutMas(int a[], int n)
{
    for (int i = 0; i<n; i++)
    {
        printf("%d ", a[i] );
    }
    printf("\n");
}

void OutPutUI(UI r, int n) {
    for (int i = n - 1; i >= 0; --i) {
        UI mask = (1 << i);
        UI res = r & mask;
        
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
