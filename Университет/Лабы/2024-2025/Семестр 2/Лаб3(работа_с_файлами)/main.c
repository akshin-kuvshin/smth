/*
Задание 24.

Текстовый файл зашифровать, сделав циклическую замену каждой буквы на
букву того же регистра, расположенную на K – й позиции после шифруемой
(0 < K < 10). Например, при K = 3 буква ‘A’ перейдет в ‘D’, ‘z’ – в ‘c’.
Символы, не являющиеся буквами, при шифровании не изменять.
*/

// author: Danila "akshin_" Axyonov

#include <stdio.h>
#include <stdbool.h>
#include <assert.h>
#include <iso646.h>
#include "char_ops.h"

const int MAX_FILENAME_LEN = 256;
const char* OUTPUT_FILENAME = "encoded.txt";

int main() {
    char input_filename[MAX_FILENAME_LEN];
    printf("Введите название шифруемого файла:\n> ");
    gets(input_filename);

    FILE* input_file = fopen(input_filename, "r");
    FILE* output_file = fopen(OUTPUT_FILENAME, "w");
    assert(input_file and output_file and "Ошибка открытия файла. Возможно, файла с введённым Вами именем не существует.");

    int k;
    printf("Введите величину сдвига (от 1 до 9 включительно):\n> ");
    scanf("%d", &k);
    assert(1 <= k and k <= 9 and "Введённая Вами величина сдвига недопустима.");



    // Основной цикл
    char c;
    while ((c = getc(input_file)) != EOF)
        if (is_lowercase(c))
            putc(shift_lowercase(c, k), output_file);
        else if (is_uppercase(c))
            putc(shift_uppercase(c, k), output_file);
        else // (c) не является латинской буквой
            putc(c, output_file);



    printf("Файл %s был успешно зашифрован. Результат Вы можете найти в файле %s.\n", input_filename, OUTPUT_FILENAME);
    
    fclose(input_file);
    fclose(output_file);
    return 0;
}
