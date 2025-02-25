// Задача 6.
// Транспонировать на том же месте квадратную булеву матрицу.

// author: Danila "akshin_" Axyonov

#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <assert.h>
#include <iso646.h>
#include "BV.h"
#include "BM.h"

const int MAX_INPUT_LEN = 1000;

int main() {
    int n;
    printf("Введите размерность булевой матрицы (от 1 до %d включительно):\n> ", MAX_BV_LEN);
    scanf("%d", &n);
    assert(1 <= n and n <= MAX_BV_LEN and "Введённая Вами размерность не удовлетворяет ограничениям!");

    BM matrix = build_BM(n);

    char input[MAX_INPUT_LEN];
    printf("Введите вашу булеву матрицу в виде последовательности 0 и 1, без пробелов и без лишних переводов строк:\n");
    fflush(stdin);
    for (int i = 0; i < n; ++i) {
        gets(input);
        int len = strlen(input);
        assert(len == n and "Длина введённой Вами строки матрицы не соответствует её размерности!");
        matrix[i] = string_to_BV(input, len);
    }

    for (int i = 0; i < n; ++i)
        for (int j = 0; j < i; ++j) {
            bool ij = get(matrix, n, i, j),
                 ji = get(matrix, n, j, i);
            if (ij != ji) {
                flip(matrix, n, i, j);
                flip(matrix, n, j, i);
            }
        }
    
    printf("\nВаша булева матрица после транспонирования:\n");
    print_BM(matrix, n);

    destroy_BM(matrix);
    return 0;
}
