#include "boyer_moore.h"

#include <iso646.h>

void fill_shift_arr(int* shift, char* word, int word_len) {
    for (int i = 0; i < SHIFT_ARR_LEN; ++i)
        shift[i] = word_len;
    for (int i = 0; i < word_len - 1; ++i)
        shift[word[i]] = (word_len - 1) - i;
    return;
}

int boyer_moore_search(char* text, int text_len, char* word, int word_len, int* shift) {
    for (int ind = word_len - 1; ind < text_len; ind += shift[text[ind]]) {
        int text_ind = ind,
            word_ind = word_len - 1;
        while (word_ind >= 0 and text[text_ind] == word[word_ind]) {
            --text_ind;
            --word_ind;
        }
        if (word_ind == -1)
            return text_ind + 1;
    }
    return NOT_FOUND;
}
