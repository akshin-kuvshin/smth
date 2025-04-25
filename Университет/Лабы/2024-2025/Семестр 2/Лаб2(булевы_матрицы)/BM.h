#ifndef __BM
#define __BM

#include <stdbool.h>
#include "BV.h"

typedef BV* BM;

BM build_BM(int n);
void destroy_BM(BM matrix);
bool get(BM matrix, int n, int row, int col);
void flip(BM matrix, int n, int row, int col);
void print_BM(BM matrix, int n);

#endif
