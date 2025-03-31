#include "array_ops.h"

#include <stdio.h>
#include "random.h"

void print_array(int* arr, int len) {
    for (int i = 0; i < len; ++i)
        printf("%d ", arr[i]);
    putchar('\n');
    return;
}

void fill_array_random_asc(int* arr, int len) {
    arr[0] = random(__RANDOM_INIT_MIN, __RANDOM_INIT_MAX);
    for (int i = 1; i < len; ++i)
        arr[i] = arr[i - 1] + random(1, __RANDOM_MAX_STEP);
    return;
}
