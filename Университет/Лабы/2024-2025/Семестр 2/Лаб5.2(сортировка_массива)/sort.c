#include "sort.h"

#include <stdbool.h>
#include <iso646.h>

void swap(int* a, int* b) {
    int tmp = *a;
    *a = *b;
    *b = tmp;
    return;
}

void upgraded_bubble_sort(int* arr, int len) {
    int R = len; // индекс элемента, с которого начинается отсортированная часть.
    while (R) {
        int new_R = 0;
        for (int i = 0; i + 1 < R; ++i)
            if (arr[i] > arr[i + 1]) {
                swap(arr + i, arr + i + 1);
                new_R = i + 1;
            }
        R = new_R;
    }
    return;
}

void shaker_sort(int* arr, int len) {
    int L = 0,
        R = len - 1;
    bool go_right = true;
    while (L < R) {
        if (go_right) {
            for (int i = L; i + 1 <= R; ++i)
                if (arr[i] > arr[i + 1])
                    swap(arr + i, arr + i + 1);
            --R;
        } else { // go_left
            for (int i = R; i - 1 >= L; --i)
                if (arr[i - 1] > arr[i])
                    swap(arr + i - 1, arr + i);
            ++L;
        }
        go_right = not go_right;
    }
    return;
}
