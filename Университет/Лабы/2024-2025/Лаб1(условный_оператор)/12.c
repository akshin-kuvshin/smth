// Задача номер 12: "Верно ли высказывание, что среди цифр заданного 3-х значного числа есть одинаковые".

#include <stdio.h>
#include <stdbool.h>

int main() {
    int num;
    printf_s("Введите трёхзначное число:\n");
    scanf_s("%d", &num);

    int d1 = num / 100,
        d2 = (num / 10) % 10,
        d3 = num % 10;
    
    bool is_equal_digits = false;
    if (d1 == d2 || d2 == d3 || d1 == d3)
        is_equal_digits = true;
    
    if (is_equal_digits) printf_s("Среди цифр числа %d есть две или три одинаковые.\n", num);
    else printf_s("Все цифры числа %d различны.\n", num);
    
    return 0;
}
