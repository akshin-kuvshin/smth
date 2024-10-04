#include <iostream>
using namespace std;

// Constants
const int Nmax = 1e5;

// Variables
int N,
    X,
    A[Nmax],
    maxAnswer,
    factAnswer;

// Functions
void input();
void solution();
void output();
int minOnSubarray(int, int);

int main() {
    input();
    solution();
    output();

    return 0;
}

void input() {
    cin >> N >> X;
    for (int i = 0; i < N; i++)
        cin >> A[i];
}

void solution() {
    for (int i = 0; i < N; i++) {
        for (int j = i; j < N; j++) {
            if (A[i] ^ A[j] == X) {
                factAnswer = minOnSubarray(i, j) * (j - i + 1);
                if (maxAnswer < factAnswer)
                    maxAnswer = factAnswer;
            }
        }
    }
}

void output() {
    cout << maxAnswer << '\n';
}

int minOnSubarray(int l, int r) {
    int _min = A[l];
    for (int i = l; i <= r; i++)
        if (_min > A[i])
            _min = A[i];
    return _min;
}
