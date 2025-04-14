#include "array_ops.h"

#include <stdio.h>
#include "random.h"

void print_array(int* arr, int len) {
    for (int i = 0; i < len; ++i)
        printf("%d ", arr[i]);
    putchar('\n');
    return;
}

void fill_array_random(int* arr, int len) {
    for (int i = 1; i < len; ++i)
        arr[i] = random(__RANDOM_MIN, __RANDOM_MAX);
    return;
}
