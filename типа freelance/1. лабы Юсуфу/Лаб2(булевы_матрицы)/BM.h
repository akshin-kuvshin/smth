// author: Danila "akshin_" Axyonov

#ifndef __BM
#define __BM

#include <stdbool.h>
#include "BV.h"

// BM - bool matrix

#define BM BV* // BV*      ===     массив из BV

int get(BM matrix, int m, int i, int j);
void set(BM matrix, int m, int i, int j, int val);
void OutPutBM(BM matrix, int n, int m);
int ColWeight(BM matrix, int n, int m, int j); // n - кол-во строк; m - кол-во столбцов; j - индекс столбца
void SwapCols(BM matrix, int n, int m, int j1, int j2); // j1 и j2 - индексы обмениваемых столбцов

#endif
