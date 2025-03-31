#include "binary_search.h"

int binary_search(int* arr, int len, int k) {
    int L = 0,
        R = len - 1;
    while (L < R) {
        int m = (L + R) >> 1;
        if (arr[m] < k)
            L = m + 1;
        else // k <= arr[m]
            R = m;
    }
    return ((arr[L] == k) ? L : NOT_FOUND);
}
