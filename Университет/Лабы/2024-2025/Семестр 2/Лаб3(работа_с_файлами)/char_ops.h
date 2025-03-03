#ifndef __CHAR_OPS
#define __CHAR_OPS

#include <stdbool.h>

#define ALPHABET_LEN 26

bool is_lowercase(char c);
bool is_uppercase(char c);
char shift_lowercase(char c, int shift);
char shift_uppercase(char c, int shift);

#endif
