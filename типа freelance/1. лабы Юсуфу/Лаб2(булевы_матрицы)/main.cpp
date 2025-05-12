// author: Danila "akshin_" Axyonov

// Задание 14.

#include <cstdio>
#include <cstdlib>
#include <ctime>

#include "BV.h"
#include "BM.h"

int main()
{
    srand(time(NULL)); // для того, чтобы рандомные числа не повторялись

    int n, // кол-во строк
        m; // кол-во столбцов
    printf("n = ");
    scanf("%d", &n);
    printf("m = ");
    scanf("%d", &m);

    if (m > 32) {
        printf("too big m\n");
        return 0;
    }

    BM matrix = new BV[n];

    char input[32];
    printf("vvedite matricu (postrochno):\n");
    for (int i = 0; i < n; ++i) {
        scanf("%s", input);
        matrix[i] = StringToBV(input, m);
    }

    // сортировка пузырьком (самая простая)
    for (int k = m - 1; k > 0; --k)
        for (int j = 0; j < k; ++j)
            if (ColWeight(matrix, n, m, j) > ColWeight(matrix, n, m, j + 1))
                SwapCols(matrix, n, m, j, j + 1);

    printf("\nmatrix with sorted columns (by their weight):\n");
    OutPutBM(matrix, n, m);

    delete[] matrix;
    return 0;
}
