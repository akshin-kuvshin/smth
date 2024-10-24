#include <cstdio>
#include <cstdlib>

#define _RAND_MIN            -100
#define _RAND_MAX            100

void print_row(int len) {
    for (int _ = 0; _ < len; ++_)
        printf_s("-");
    printf_s("\n");
    return;
}

void array_input(int *A, int N) {
    for (int i = 0; i < N; ++i)
        scanf_s("%d", &A[i]);
    return;
}

void array_output(const int *A, int N) {
    for (int i = 0; i < N; ++i)
        printf_s("|%3d", A[i]);
    printf_s("|\n");
    return;
}

void matrix_input(int **A, int N, int M) {
    for (int i = 0; i < N; ++i)
        array_input(A[i], M);
    return;
}

void matrix_output(int **A, int N, int M) {
    print_row(4 * M + 1);
    for (int i = 0; i < N; ++i) {
        array_output(A[i], M);
        print_row(4 * M + 1);
    }
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

void fill_array_random(int *A, int N) {
    for (int i = 0; i < N; ++i)
        A[i] = rand() % (_RAND_MAX - _RAND_MIN + 1) + _RAND_MIN;
    return;
}

void fill_matrix_random(int **A, int N, int M) {
    for (int i = 0; i < N; ++i)
        fill_array_random(A[i], M);
    return;
}

void matrix_max_ind(int **A, int N, int M, int *r, int *c) {
    *r = *c = 0;
    int max_elem = A[0][0];
    for (int i = 0; i < N; ++i)
        for (int j = 0; j < M; ++j)
            if (A[i][j] > max_elem) {
                *r = i;
                *c = j;
                max_elem = A[i][j];
            }
    return;
}

void _swap(int *a, int *b) { // also we can use signature like "int &a, int &b"
    int tmp = *a;
    *a = *b;
    *b = tmp;
    return;
}

void swap_arrays(int *A, int *B, int N) {
    for (int i = 0; i < N; ++i)
        _swap(&A[i], &B[i]);
    return;
}

void swap_rows(int **A, int M, int i, int j) {
    swap_arrays(A[i], A[j], M);
    return;
}

void swap_columns(int **A, int N, int i, int j) {
    for (int row = 0; row < N; ++row)
        _swap(&A[row][i], &A[row][j]);
    return;
}

int** matrix(int N, int M) {
    int **A = new int*[N];
    for (int i = 0; i < N; ++i)
        A[i] = new int[M];
    return A;
}

void clear(int **A, int N) {
    for (int i = 0; i < N; ++i)
        delete[] A[i];
    delete[] A;
}
