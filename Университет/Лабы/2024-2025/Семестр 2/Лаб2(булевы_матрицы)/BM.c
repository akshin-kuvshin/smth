#include <stdlib.h>
#include <assert.h>
#include <iso646.h>
#include "BV.h"
#include "BM.h"

BM build_BM(int n) {
    BM matrix = (BM)calloc(n, sizeof(BV));
    assert(matrix and "Не удалось выделить память.");
    return matrix;
}

void destroy_BM(BM matrix) {
    free(matrix);
    return;
}

bool get(BM matrix, int n, int row, int col) {
    BV mask = (1ULL << (n - 1 - col));
    return (bool)(matrix[row] & mask);
}

void flip(BM matrix, int n, int row, int col) {
    BV mask = (1ULL << (n - 1 - col));
    matrix[row] ^= mask;
    return;
}

void print_BM(BM matrix, int n) {
    for (int i = 0; i < n; ++i)
        print_BV(matrix[i], n);
    return;
}
