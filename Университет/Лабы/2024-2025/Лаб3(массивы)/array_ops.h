#include <stdbool.h>

void array_input(int*, int);                // Ввод массива
void array_output(const int*, int);         // Вывод массива
bool is_sorted(const int*, int);            // Проверка массива на отсортированность по неубыванию
void array_leftshift(int*, int, int);       // Исключение из массива элемента циклическим сдвигом влево
