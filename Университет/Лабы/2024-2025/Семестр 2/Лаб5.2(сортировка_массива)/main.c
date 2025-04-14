// author: Danila "akshin_" Axyonov
//
// Задание:
//
// 1) Создать динамический массив из n случайных чисел (10 <= n <= 100.000).
// 2) Сортировать массив методами улучшенного пузырька (с отслеживанием места последнего обмена)
// и шейкера (обычного, без отслеживания обменов).
// 3) Сравнить и проанализировать время выполнения сортировок.
//
// Замечание: программа без дополнительного редактирования кода должна обеспечить
// при n <= 30 вывод на экран исходного, отсортированного массивов и времени сортировок,
// при n > 30 - только время сортировок (массивы не выводить).

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <assert.h>
#include <iso646.h>
#include "array_ops.h"
#include "sort.h"

const int N_MIN = 10,
          N_MAX = 100000,
          PRINT_BORDER = 30;

void print_array_with_header(int* arr, int len, const char* header);
void copy(int* from, int len, int* to);

int main() {
    srand(time(NULL));
    putchar('\n');

    int n;
    printf("Введите длину массива (от 10 до 100.000 включительно):\n> ");
    scanf("%d", &n);
    assert(N_MIN <= n and n <= N_MAX and "Введённая длина массива недопустима");

    int* original_array = (int*)calloc(n, sizeof(int));
    int* sorting_array = (int*)calloc(n, sizeof(int));
    assert(original_array and sorting_array and "Не удалось выделить память под массив");

    fill_array_random(original_array, n);
    if (n <= PRINT_BORDER)
        print_array_with_header(original_array, n, "Исходный массив");
    

    
    clock_t start,
            finish;
    double t;



    // 1) Тестируем улучшенный пузырёк

    copy(original_array, n, sorting_array);
    start = clock();
    upgraded_bubble_sort(sorting_array, n);
    finish = clock();

    if (n <= PRINT_BORDER)
        print_array_with_header(sorting_array, n, "Массив, отсортированный методом улучшенного пузырька");
    
    t = (double)(finish - start) / CLOCKS_PER_SEC;
    printf("Времени затрачено на сортировку методом улучшенного пузырька (в секундах): %.3lf.\n", t);



    // 2) Тестируем шейкер

    copy(original_array, n, sorting_array);
    start = clock();
    shaker_sort(sorting_array, n);
    finish = clock();

    if (n <= PRINT_BORDER)
        print_array_with_header(sorting_array, n, "Массив, отсортированный методом шейкера");
    
    t = (double)(finish - start) / CLOCKS_PER_SEC;
    printf("Времени затрачено на сортировку методом шейкера (в секундах): %.3lf.\n", t);
    
    return 0;
}

void print_array_with_header(int* arr, int len, const char* header) {
    putchar('\n');
    printf("<---%s--->\n", header);
    print_array(arr, len);
    return;
}

void copy(int* from, int len, int* to) {
    for (int i = 0; i < len; ++i)
        to[i] = from[i];
    return;
}
