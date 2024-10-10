#include <stdio.h>
#include <stdbool.h>

void array_input(int *A, int N) {
    for (int i = 0; i < N; ++i)
        scanf_s("%d", &A[i]);
    return;
}

void array_output(const int *A, int N) {
    for (int i = 0; i < N; ++i)
        printf_s("%d ", A[i]);
    printf_s("\n");
    return;
}

bool is_sorted(const int *A, int N) {
    for (int i = 1; i < N; ++i)
        if (A[i - 1] > A[i])
            return false;
    return true;
}

void array_leftshift(int *A, int N, int pos) {
    for (int i = pos; i + 1 < N; ++i)
        A[i] = A[i + 1];
    return;
}
