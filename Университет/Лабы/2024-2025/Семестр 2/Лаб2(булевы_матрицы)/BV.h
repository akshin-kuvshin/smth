#ifndef __BV
#define __BV

typedef unsigned long long int BV;
#define MAX_BV_LEN 64

BV string_to_BV(const char* S, int len);
void print_BV(BV V, int n);

#endif
