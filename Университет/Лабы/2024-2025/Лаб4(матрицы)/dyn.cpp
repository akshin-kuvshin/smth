// Задача: дана прямоугольная матрица. Переставляя её строки и столбцы, переместить наибольший элемент матрицы в верхний левый угол.
// ВАРИАНТ ДИНАМИЧЕСКОЙ МАТРИЦЫ (с визуализацией, но чуть менее оптимизированный [сделано это намеренно для красоты визуализации])

#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <unistd.h>
#include "array_matrix_ops.h"

// P.S.: здесь используется команда "clear", которая работает в Linux-подобных терминалах, поэтому не запускать через всякие cmd и PowerShell!!!
const char *clear_command = "clear";

int main() {
    srand(time(NULL));
    system(clear_command);

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
    int r, c;
    matrix_max_ind(A, N, M, &r, &c);
    
    system(clear_command);
    printf_s("Ваша случайно сгенерированная матрица:\n");
    matrix_output_with_highlighting(A, N, M, r, c);
    printf_s("Позиция максимального элемента: %d строка, %d столбец.", r + 1, c + 1);
    sleep(5);

    system(clear_command);
    matrix_output_with_highlighting(A, N, M, r, c);
    sleep(2);
    // Здесь и далее перемещаю только соседние строки/столбцы (т.е. перемещаю наибольший элемент только на одну позицию вверх/влево) для удобства визуализации.
    while (r > 0) {
        system(clear_command);
        swap_rows(A, M, r, r - 1);
        matrix_output_with_highlighting(A, N, M, --r, c);
        sleep(2);
    }
    while (c > 0) {
        system(clear_command);
        swap_columns(A, N, c, c - 1);
        matrix_output_with_highlighting(A, N, M, r, --c);
        sleep(2);
    }

    printf_s("Программа завершена успешно: максимальный элемент матрицы теперь в верхнем левом углу!\n");

    clear(A, N);
    return 0;    
}
