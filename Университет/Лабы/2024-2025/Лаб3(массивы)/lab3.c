// Условие задачи: дан массив целых чисел, элементы которого расположены по неубыванию. Требуется исключить из массива одинаковые элементы, причём исключения производить циклическим сдвигом влево.

#include <stdio.h>
#include <stdbool.h>

void array_input(int*, int);                // Ввод массива
void array_output(const int*, int);         // Вывод массива
bool is_sorted(const int*, int);            // Проверка массива на отсортированность по неубыванию
void array_leftshift(int*, int, int);       // Исключение из массива элемента циклическим сдвигом влево

int main() {
    const int MAX_SIZE = 1000;
    int A[MAX_SIZE];

    int N;
    printf_s("Введите длину массива (от 1 до %d включительно):\n> ", MAX_SIZE);
    scanf_s("%d", &N);
    while (N < 1 || MAX_SIZE < N) {
        printf_s("Ошибка: введено некорректное значение длины массива! Пожалуйста, попробуйте ещё раз, введя натуральное число от 1 до %d включительно:\n> ", MAX_SIZE);
        scanf_s("%d", &N);
    }

    printf_s("Теперь введите %d элементов массива: целые числа, расположенные в порядке неубывания:\n> ", N);
    array_input(A, N);
    while (!is_sorted(A, N)) {
        printf_s("Ошибка: введённый Вами массив не отсортирован! Пожалуйста, попробуйте ещё раз, введя %d целых чисел, расположенных в порядке неубывания:\n> ", N);
        array_input(A, N);
    }

    for (int i = 1; i < N;)
        if (A[i - 1] == A[i]) // Элемент A[i] исключается из массива, i остаётся прежним, N уменьшается на 1.
            array_leftshift(A, N--, i);
        else ++i;
    
    printf_s("Ваш массив, в котором оставлены только уникальные элементы:\n");
    array_output(A, N);

    return 0;
}

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
