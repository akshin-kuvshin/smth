#include <iostream>
#define uint unsigned int
using namespace std;

// Constants
const int N_max = 512;

// Functions
int tests_number;

int main() {
    cin >> tests_number;
    int answers[128 + 5];

    for (int t = 0; t < tests_number; ++t) {
        uint N,
             A[N_max + 5];
        
        cin >> N;
        for (int i = 0; i < N; ++i)
            cin >> A[i];
        
        uint _min = A[0],
             _max = A[0];
        for (int i = 1; i < N; ++i) {
            _min = min(_min, A[i]);
            _max = max(_max, A[i]);
        }

        for (uint shift = 0; shift <= 10; ++shift) {
            for (int i = 0; i < N; ++i) {
                if (((A[i] >> shift) & 1) == 0) {
                    if (((_min >> shift) & 1) == 1)
                        _min -= (1 << shift);
                } else { // A[i] & pow2 != 0
                    if (((_max >> shift) & 1) == 0)
                        _max += (1 << shift);
                }
            }
        }

        answers[t] = _max - _min;
    }

    for (int t = 0; t < tests_number; ++t)
        cout << answers[t] << '\n';

    return 0;
}
