#include <stdio.h>

int main() {
    double res = 0.;

    int fact = 1;
    // Считаем только первые 10 членов ряда, потому что остальные, очевидно,
    // на первые три знака после запятой никак не повлияют, потому что будут слишком малы.
    //
    // Вообще, честно говоря, этот ряд сходится к e-1, где e - это второй замечательный предел,
    // т.е. число Эйлера.
    for (int i = 1; i <= 10; ++i) {
        // Не считаем каждый факториал заново, а "досчитываем его"
        // на основе предыдущего.
        fact *= i;
        res += 1. / fact;
    }

    printf("Сумма вида 1 + 1/2! + 1/3! + ... равна %.3f\n", res);
    return 0;
}
