void print_row(int);                                                // Вывод строки, состоящей из тире
void array_input(int*, int);                                        // Ввод массива
void array_output(const int*, int);                                 // Вывод массива
void matrix_input(int**, int, int);                                 // Ввод матрицы (динамической)
void matrix_output(int**, int, int);                                // Вывод матрицы (динамической)
void matrix_output_with_highlighting(int**, int, int, int, int);
bool is_sorted(const int*, int);                                    // Проверка массива на отсортированность по неубыванию
void array_leftshift(int*, int, int);                               // Исключение из массива элемента циклическим сдвигом влево
void fill_array_random(int*, int);                                  // Заполнение массива случайными числами от RAND_MIN до RAND_MAX (см. array_ops.cpp)
void fill_matrix_random(int**, int, int);                           // Заполнение матрицы (динамической) случайными числами от RAND_MIN до RAND_MAX (см. array_ops.cpp)
void matrix_max_ind(int**, int, int, int*, int*);                   // Нахождение позиции наибольшего эл-та в матрице (динамической)
void _swap(int*, int*);                                             // Обмен значений между двумя переменными типа int
void swap_arrays(int*, int*, int);                                  // Обмен значений между двумя массивами
void swap_rows(int**, int, int, int);                               // Перестановка строк в матрице (динамической)
void swap_columns(int**, int, int, int);                            // Перестановка столбцов в матрице (динамической)
int** matrix(int, int);                                             // Создание динамической матрицы (в т.ч. выделение памяти под неё)
void clear(int**, int);                                             // Удаление динамической матрицы (в т.ч. освобождение памяти из-под неё)
