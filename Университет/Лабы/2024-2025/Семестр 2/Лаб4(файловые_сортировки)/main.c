/*
Задание: реализовать алгоритм файловой сортировки естественным слиянием.
*/

// author: Danila "akshin_" Axyonov

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <assert.h>
#include <iso646.h>
#include "natural_merge.h"

const int MAX_FILENAME_LEN = 256;

int main() {
    char input_filename[MAX_FILENAME_LEN];
    printf("Введите название сортируемого файла:\n> ");
    gets(input_filename);
    assert(not empty(input_filename) and "Ошибка. Сортируемый файл пуст.");

    printf("Исходный файл ");
    print_file(input_filename);
    


    int cnt = 0;
    split_and_log(input_filename);
    while (not empty("G2.txt")) {
        merge_and_log(input_filename);
        printf("Проход #%d завершён.\n\n", ++cnt);
        split_and_log(input_filename);
    }
    puts("Файл G2.txt пуст => Сортировка окончена.\n");


    
    printf("Отсортированный файл ");
    print_file(input_filename);
    printf("Общее количество выполненных проходов: %d.\n", cnt);

    system("rm G1.txt G2.txt");
    return 0;
}
