// Задача номер 4: "Вывести на экран все двухзначные числа, в записи которых все цифры чётные".

#include <stdio.h>

int main() {
    printf_s("Двузначные числа, в записи которых все цифры чётные (while):\n");
    int num = 10;
    while (num < 100) {
        int d1 = num / 10,
            d2 = num % 10;
        if (d1 % 2 == 0 && d2 % 2 == 0)
            printf_s("%d ", num);
        ++num;
    }
    printf_s("\n");

    printf_s("Двузначные числа, в записи которых все цифры чётные (do-while):\n");
    num = 10;
    do {
        int d1 = num / 10,
            d2 = num % 10;
        if (d1 % 2 == 0 && d2 % 2 == 0)
            printf_s("%d ", num);
        ++num;
    } while (num < 100);
    printf_s("\n"); 

    printf_s("Двузначные числа, в записи которых все цифры чётные (for):\n");
    for (num = 10; num < 100; ++num) {
        int d1 = num / 10,
            d2 = num % 10;
        if (d1 % 2 == 0 && d2 % 2 == 0)
            printf_s("%d ", num);
    }
    printf_s("\n"); 
    return 0;
}
