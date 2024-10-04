#include <iostream>
using namespace std;

const int N_max = 1e2;

int N,
    A[N_max + 5];

void input();
void solution();
void output();

int main() {
    input();
    solution();
    output();

    return 0;
}

void input() {
    cin >> N;
    for (int i = 1; i <= N; ++i)
        cin >> A[i];
    return;
}

void solution() {
    A[1] -= 1;

    for (int i = 2; i <= N; ++i) {
        int speed = i;

        A[i] -= speed;
        if (A[i] <= A[i - 1]) // случайно обогнал
            A[i] = A[i - 1] + 1;
    }

    return;
}

void output() {
    for (int i = 1; i <= N; ++i)
        cout << A[i] << '\n';
    return;
}
