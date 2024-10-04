#include <iostream>
using namespace std;

const int N_max = 1e3;

int counter,
    N,
    A[N_max + 5];

int main() {
    cin >> N;
    for (int i = 0; i < N; ++i)
        cin >> A[i];

    bool isNeedToCheck = false;
    do {
        isNeedToCheck = false;
        for (int i = 0; i < N - 1; ++i)
            if (A[i] > A[i + 1]) {
                swap(A[i], A[i + 1]);
                ++counter;
                isNeedToCheck = true;
            }
    } while (isNeedToCheck);

    cout << counter << '\n';
    return 0;
}
