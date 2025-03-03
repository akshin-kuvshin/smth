#include "char_ops.h"

#include <stdbool.h>
#include <iso646.h>

bool is_lowercase(char c) {
    return 'a' <= c and c <= 'z';
}

bool is_uppercase(char c) {
    return 'A' <= c and c <= 'Z';
}

char shift_lowercase(char c, int shift) {
    c -= 'a';
    c = (c + shift) % ALPHABET_LEN;
    c += 'a';
    return c;
}

char shift_uppercase(char c, int shift) {
    c -= 'A';
    c = (c + shift) % ALPHABET_LEN;
    c += 'A';
    return c;
}
