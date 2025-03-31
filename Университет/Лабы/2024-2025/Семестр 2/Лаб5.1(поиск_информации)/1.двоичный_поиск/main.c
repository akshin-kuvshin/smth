// author: Danila "akshin_" Axyonov

// Задача 2. Создать возрастающий массив из N случайных целых чисел.
// Определить, используя бинарный пoиск, входит ли в него число k,
// если входит, то вывести его индекс в массиве.

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <assert.h>
#include <iso646.h>
#include "array_ops.h"
#include "binary_search.h"

int main() {
    srand(time(NULL));

    int len;
    printf("\nВведите длину массива для заполнения:\n> ");
    scanf("%d", &len);
    assert(len > 0 and "Длина массива должна быть положительным числом");
    
    int* arr = (int*)calloc(len, sizeof(int));
    assert(arr and "Не удалось выделить память под массив");
    fill_array_random_asc(arr, len);
    printf("\nПолученный массив: ");
    print_array(arr, len);

    int k;
    printf("\nВведите число (k) для поиска в массиве выше:\n> ");
    scanf("%d", &k);

    int ind = binary_search(arr, len, k);
    if (ind == NOT_FOUND)
        printf("\nВведённое Вами число отсутствует в массиве.\n");
    else
        printf("\nВведённое Вами число присутствует в массиве под индексом %d (нумерация с нуля).\n", ind);

    free(arr);
    return 0;
}
