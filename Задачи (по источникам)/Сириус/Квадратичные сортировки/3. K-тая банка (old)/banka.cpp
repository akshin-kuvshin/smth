#include <iostream>
using namespace std;

const int N_max = 1e5;

int N,
    K,
    A[N_max + 5];

void _sort(int*, int, int);

int main() {
    cin >> N >> K;
    for (int i = 0; i < N; ++i)
        cin >> A[i];

    _sort(A, K, N);

    cout << A[K - 1];
}

void _sort(int *arr, int bord, int sz) {
    int ind_max,
        _max;
    for (int i = 0; i < bord; ++i) {
        ind_max = i;
        _max = arr[i];

        for (int j = i + 1; j < sz; ++j)
            if (A[j] > _max) {
                ind_max = j;
                _max = arr[j];
            }

        swap(arr[i], arr[ind_max]);
    }
    return;
}
