#ifndef __NATURAL_MERGE
#define __NATURAL_MERGE

#include <stdbool.h>

void print_file(const char* filename);
bool empty(const char* filename);
void split_and_log(const char* input_filename);
void merge_and_log(const char* input_filename);

#endif
