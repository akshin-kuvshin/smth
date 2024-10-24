// Задача: дана прямоугольная матрица. Переставляя её строки и столбцы, переместить наибольший элемент матрицы в верхний левый угол.
// ВАРИАНТ ДИНАМИЧЕСКОЙ МАТРИЦЫ

#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <unistd.h>
#include "array_matrix_ops.h"

int main() {
    srand(time(NULL));

    int N,
        M;
    printf_s("Введите два числа - размерности вашей матрицы - т.е. кол-во строк и кол-во столбцов соответственно:\n> ");
    scanf_s("%d%d", &N, &M);
    while (N <= 0 or M <= 0) {
        printf_s("Введённые Вами значения некорректны, попробуйте ещё раз:\n> ");
        scanf_s("%d%d", &N, &M);
    }

    int **A = matrix(N, M);
    fill_matrix_random(A, N, M);
    
    system("clear");
    printf_s("Ваша случайно сгенерированная матрица:\n");
    matrix_output(A, N, M);

    int r, c;
    matrix_max_ind(A, N, M, &r, &c);
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

    printf_s("Программа завершена успешно: максимальный элемент матрицы теперь в верхнем левом углу!\n");

    clear(A, N);
    return 0;    
}
