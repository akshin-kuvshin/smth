#include <iostream>
using namespace std;

const int N_max = 1e5;
const double eps = 1e-6;

int N,
    A[N_max + 5],
    mins[N_max + 5],
    mins_ind[N_max + 5];

double ratio = -1.;
pair<int, int> ans_ind;

double _abs(double);

int main() {
    /* input */
    cin >> N;
    for (int i = 0; i < N; ++i)
        cin >> A[i];
    
    /* solution */
    mins[0] = A[0];
    mins_ind[0] = 0;
    for (int i = 1; i < N; ++i) {
        // Ищем новый минимум и его индекс на отрезке [0, i]
        if (mins[i - 1] > A[i]) {
            mins[i] = A[i];
            mins_ind[i] = i;
        } else {
            mins[i] = mins[i - 1];
            mins_ind[i] = mins_ind[i - 1];
        }

        // Ищем новое наибольшее отношение
        if ((double)A[i] / mins[i - 1] > ratio) {
            ratio = (double)A[i] / mins[i - 1];
            ans_ind = make_pair(mins_ind[i - 1], i);
        }
    }

    // Если найденное отношение больше единицы, то выводим два нуля
    if (_abs(ratio - 1.) < eps) // Сравнение чисел типа double
        ans_ind = make_pair(-1, -1);

    /* output */
    cout << ans_ind.first + 1 << ' ' << ans_ind.second + 1 << '\n';
    return 0;
}

double _abs(double number) {
    return ( (number >= 0) ? number : -number );
}
