#include <iostream>
#include <array>
using namespace std;

const int T_max = 1e4,
          N_max = 1e5;

int T;
array<int, T_max + 5> answers;

int N,
    K;
array<int, N_max + 5> A;

int main() {
    cin >> T;

    for (int _t = 0; _t < T; ++_t) {
        cin >> N >> K;
        for (int i = 0; i < N; ++i)
            cin >> A.at(i);
        
        int current = 0;
        for (int i = 0; i < N; ++i)
            if (A[i] == current + 1)
                ++current;
        
        answers.at(_t) = (N - current) / K + (((N - current) % K) ? 1 : 0);
    }

    for (int _t = 0; _t < T; ++_t)
        cout << answers.at(_t) << '\n';
    
    return 0;
}
