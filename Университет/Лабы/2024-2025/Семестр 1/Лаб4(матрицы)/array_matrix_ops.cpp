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
        printf_s("|%4d", A[i]);
    printf_s("|\n");
    return;
}

void matrix_input(int **A, int N, int M) {
    for (int i = 0; i < N; ++i)
        array_input(A[i], M);
    return;
}

void matrix_output(int **A, int N, int M) {
    print_row(5 * M + 1);
    for (int i = 0; i < N; ++i) {
        array_output(A[i], M);
        print_row(5 * M + 1);
    }
    return;
}

void matrix_output_with_highlighting(int **A, int N, int M, int i, int j) {
    printf_s("    "); // 4 пробела: 2, чтобы дойти до первой ячейки; 2, чтобы дойти до нужного места в ячейке
    for (int _ = 0; _ < j; ++_)
        printf_s("     "); // 5 пробелов, чтобы перейти к идентичной позиции в следующей ячейке
    printf_s("|\n "); // Ставим "стрелочку", переходим на новую строку и ставим пробел, чтобы вызов print_row не съехал влево
    print_row(5 * M + 1);
    for (int _i = 0; _i < N; ++_i) {
        // Здесь и далее все пробелы нужны, чтобы вся таблица не съехала влево
        // Один из пробелов заменяется "стрелочкой"
        printf_s((_i == i) ? "-" : " ");
        array_output(A[_i], M);
        printf_s(" ");
        print_row(5 * M + 1);
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

void swap_rows(int **A, int i, int j) {
    int *tmp = A[i];
    A[i] = A[j];
    A[j] = tmp;
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
