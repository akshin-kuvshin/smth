// Задача: дана прямоугольная матрица. Переставляя её строки и столбцы, переместить наибольший элемент матрицы в верхний левый угол.
// ВАРИАНТ СТАТИЧЕСКОЙ МАТРИЦЫ

#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <unistd.h>

#define _RAND_MIN            -100
#define _RAND_MAX            100

const int MAX_SIZE = 100;

// Не могу использовать библиотеку, т.к. функции в ней написаны для динамических матриц - более универсальных вариантов.
void print_row(int);
void array_output(const int*, int);
void matrix_output(const int[][MAX_SIZE], int, int);
void fill_array_random(int*, int);
void fill_matrix_random(int[][MAX_SIZE], int, int);
void get_max_ind(int[][MAX_SIZE], int, int, int*, int*);
void _swap(int*, int*);
void swap_rows(int[][MAX_SIZE], int, int, int);
void swap_columns(int[][MAX_SIZE], int, int, int);

int main() {
    srand(time(NULL));

    int A[MAX_SIZE][MAX_SIZE];

    int N,
        M;
    printf_s("Введите два числа - размерности вашей матрицы - т.е. кол-во строк и кол-во столбцов соответственно:\n> ");
    scanf_s("%d%d", &N, &M);
    while (N <= 0 or M <= 0) {
        printf_s("Введённые Вами значения некорректны, попробуйте ещё раз:\n> ");
        scanf_s("%d%d", &N, &M);
    }

    fill_matrix_random(A, N, M);
    
    system("clear");
    printf_s("Ваша случайно сгенерированная матрица:\n");
    matrix_output(A, N, M);

    int r, c;
    get_max_ind(A, N, M, &r, &c);
    printf_s("Позиция максимального элемента: %d строка, %d столбец.", r + 1, c + 1);

    sleep(8);
    for (int i = r; i > 0; --i) {
        system("clear");
        swap_rows(A, M, i, i - 1);
        matrix_output(A, N, M);
        sleep(1);
    }
    for (int j = c; j > 0; --j) {
        system("clear");
        swap_columns(A, N, j, j - 1);
        matrix_output(A, N, M);
        sleep(1);
    }

    return 0;    
}

void print_row(int len) {
    for (int _ = 0; _ < len; ++_)
        printf_s("-");
    printf_s("\n");
    return;
}
void array_output(const int *A, int N) {
    for (int i = 0; i < N; ++i)
        printf_s("|%3d", A[i]);
    printf_s("|\n");
    return;
}
void matrix_output(const int A[][MAX_SIZE], int N, int M) {
    print_row(4 * M + 1);
    for (int i = 0; i < N; ++i) {
        array_output(A[i], M);
        print_row(4 * M + 1);
    }
    return;
}
void fill_array_random(int *A, int N) {
    for (int i = 0; i < N; ++i)
        A[i] = rand() % (_RAND_MAX - _RAND_MIN + 1) + _RAND_MIN;
    return;
}
void fill_matrix_random(int A[][MAX_SIZE], int N, int M) {
    for (int i = 0; i < N; ++i)
        fill_array_random(A[i], M);
    return;
}
void get_max_ind(int A[][MAX_SIZE], int N, int M, int *r, int *c) {
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
void _swap(int *a, int *b) {
    int tmp = *a;
    *a = *b;
    *b = tmp;
    return;
}
void swap_rows(int A[][MAX_SIZE], int M, int i, int j) {
    for (int col = 0; col < M; ++col)
        _swap(&A[i][col], &A[j][col]);
    return;
}
void swap_columns(int A[][MAX_SIZE], int N, int i, int j) {
    for (int row = 0; row < N; ++row)
        _swap(&A[row][i], &A[row][j]);
    return;
}
