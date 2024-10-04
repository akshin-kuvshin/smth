#include <stdio.h>
#include <conio.h>

int main() {
    int x,
        y;
    printf_s("Введите два числа:\n");
    scanf_s("%d%d", &x, &y);

    int max = x;
    if (max < y)
        max = y;
    printf_s("max(%d, %d) = %d\n", x, y, max);

    _getch();
    return 0;
}
