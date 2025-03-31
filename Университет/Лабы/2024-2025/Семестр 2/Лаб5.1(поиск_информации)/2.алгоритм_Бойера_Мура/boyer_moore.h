#ifndef __BOYER_MOORE
#define __BOYER_MOORE

#define SHIFT_ARR_LEN 256
#define NOT_FOUND -1

void fill_shift_arr(int* shift, char* word, int word_len);
int boyer_moore_search(char* text, int text_len, char* word, int word_len, int* shift);

#endif
