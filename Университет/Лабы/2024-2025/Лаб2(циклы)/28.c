// Задача номер 28: "Вычислить сумму квадратов всех целых чисел, попадающих в интервал (ln(x); e^x)".
// P.S.: насколько я понял, в соответствующий интервал должны попадать сами числа, а не их квадраты.

#include <stdio.h>
#include <math.h>

int _ceil(double num) {
    return (int)num + 1;
}

int _floor(double num) {
    return (int)num;
}

int main() {
    double x;
    printf_s("Введите положительное вещественное число:\n> ");
    scanf_s("%lf", &x);
    while (x < 0.) {
        printf_s("Введённое Вами вещественное число не является положительным, попробуйте ещё раз:\n> ");
        scanf_s("%lf", &x);
    }
    
    double lnx = log(x),
           ex = exp(x);
    int start = _ceil(lnx),
        finish = _floor(ex);

    long long sq_sum = 0LL;
    for (int n = start; n <= finish; ++n)
        sq_sum += n * n;
    
    printf_s("Сумма квадратов всех целых чисел, попадающих в интервал от ln(%f)=%.2f до exp(%f)=%.2f равняется %lli.\n", x, lnx, x, ex, sq_sum);
    return 0;
}
