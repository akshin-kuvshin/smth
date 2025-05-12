// author: Danila "akshin_" Axyonov

#include "BV.h"
#include "BM.h"

int get(BM matrix, int m, int i, int j) {
    BV mask = (1 << (m - j - 1));
    BV res = matrix[i] & mask;
    if (res != 0)
        return 1;
    // else // res == 0
        return 0;
}

//                |         // хотим поставить 0
// m[i]:        1111001
// mask:        0010000
// ~mask:       1101111
// m[i] & mask: 1101001
void set(BM matrix, int m, int i, int j, int val) {
    BV mask = (1 << (m - j - 1));
    if (val == 1)
        matrix[i] |= mask;
    else // val == 0
        matrix[i] &= ~mask;
    return;
}

void OutPutBM(BM matrix, int n, int m) { // n - кол-во строк; m - кол-во столбцов
    for (int i = 0; i < n; ++i)
        OutPutBV(matrix[i], m);
    return;
}

int ColWeight(BM matrix, int n, int m, int j) {
    int w = 0;
    for (int i = 0; i < n; ++i)
        w += get(matrix, m, i, j);
    return w;
}

void SwapCols(BM matrix, int n, int m, int j1, int j2) {
    for (int i = 0; i < n; ++i) {
        int tmp = get(matrix, m, i, j1);
        set(matrix, m, i, j1, get(matrix, m, i, j2));
        set(matrix, m, i, j2, tmp);

        /*
        
        int val1 = get(matrix, n, i, j1),
            val2 = get(matrix, n, i, j2);
        set(matrix, n, i, j1, val2);
        set(matrix, n, i, j2, val1);

        */
    }
    return;
}
