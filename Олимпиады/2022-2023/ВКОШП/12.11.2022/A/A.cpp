#include <iostream>
#define l 0
#define r 1
#define k 2
using namespace std;

const int q_max = 1e5,
          N_max = 3 * 1e5;

int q,
    requests[3][q_max + 5],
    r_max,
    sums[N_max + 5][16 + 5];
int divisors_amount[N_max + 5];
bool factors[N_max + 5][100];

int main() {
    cin >> q;
    for (int i = 0; i < q; ++i) {
        cin >> requests[l][i] >> requests[r][i] >> requests[k][i];
        r_max = max(r_max, requests[r][i]);
    }

    // Отмечаем все числа до максимального в таблице, где строчки - сами числа,
    // а столбцы - кол-во делителей (ставим в ячейке плюсик).
    int tmp;
    bool flag;
    for (int i = 2; i <= r_max; ++i) {
        flag = false;
        for (int j = 2; j * j <= i; ++j)
            if (i % j == 0) {
                tmp = divisors_amount[i / j] + 1;
                flag = true;
                break;
            }
        
        if (!flag)
            tmp = 1;
        
        factors[i][tmp] = true;
        divisors_amount[i] = tmp;
    }

    // Считаем, сколько у нас чисел, имеющих k простых делителей в разложении,
    // на промежутке от 2 до i
    for (int i = 2; i <= r_max; ++i)
        for (int j = 1; j <= 16; ++j)
            sums[i][j] = sums[i - 1][j] - (int)factors[i][j];

    // хуячим ответ
    for (int i = 0; i < q; ++i) {
        cout << sums[requests[l][i] - 1][requests[k][i]] - sums[requests[r][i]][requests[k][i]] << '\n';
    }

    return 0;
}
