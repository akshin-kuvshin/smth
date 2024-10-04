#include <iostream>
using namespace std;

const int N_max = 1e2;

int N,
    K,
    A[N_max + 5];

int main() {
    cin >> N >> K;
    for (int i = 0; i < N; ++i)
        A[i] = N - i;

    int counter = N * (N - 1) / 2 - K;
    for (int i = 0; counter; ++i)
        for (int j = 0; j < N - 1 and counter; ++j)
            if (A[j] > A[j + 1]) {
                swap(A[j], A[j + 1]);
                --counter;
            }

    for (int i = 0; i < N; ++i)
        cout << A[i] << ' ';
    cout << '\n';
    return 0;
}
