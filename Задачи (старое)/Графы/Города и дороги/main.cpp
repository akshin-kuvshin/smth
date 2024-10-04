#include <iostream>
using namespace std;

// Constants
const int N_max = 1e2;

// Variables
int N,
    roots[N_max + 5][N_max + 5],
    roots_amount;

// Functions
void input() {
    cin >> N;
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            cin >> roots[i][j];
    return;
}

void solution() {
    for (int i = 0; i < N; i++)
        for (int j = i + 1; j < N; j++)
            roots_amount += roots[i][j];
    return;
}

void output() {
    cout << roots_amount << '\n';
    return;
}

int main() {
    input();
    solution();
    output();

    return 0;
}
