#include <iostream>
using namespace std;

const int N_max = 1e2;

int N,
    A[N_max + 5];

void _out();

int main() {
    cin >> N;
    for (int i = 0; i < N; ++i)
        cin >> A[i];

    bool is_need_to_out = false;
    for (int i = 0; i < N; ++i, is_need_to_out = false) {
        for (int j = i - 1; j >= 0; --j) {
            if (A[j] > A[j + 1]) {
                swap(A[j], A[j + 1]);
                is_need_to_out = true;
            } else if (is_need_to_out) break;
        }

        if (is_need_to_out) _out();
    }

    return 0;
}

void _out() {
    for (int i = 0; i < N; ++i)
        cout << A[i] << ' ';
    cout << '\n';
}
