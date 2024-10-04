#include <iostream>
#include <algorithm>
using namespace std;

// Constants
const int N_max = 100;

// Variables
int t;
int N;
int A[N_max + 5][N_max + 5],
    P[N_max + 5];
bool pref[N_max + 5][N_max + 5];

// Functions
void input();
void solution();
void output();
bool comp(int, int);

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin >> t;
    while (t--) {
        input();
        solution();
        output();
    }
    return 0;
}

void input() {
    cin >> N;
    for (int i = 0; i < N; ++i)
        for (int j = 0; j + 1 < N; ++j)
            cin >> A[i][j];
    return;
}

void solution() {
    for (int row = 0; row < 3; ++row)
        for (int i = 0; i + 1 < N; ++i)
            for (int j = i + 1; j + 1 < N; ++j) {
                int num1 = A[row][i],
                    num2 = A[row][j];
                pref[num1][num2] = 1;
                pref[num2][num1] = 0;
            }

    for (int i = 0; i < N; ++i)
        P[i] = i + 1;
    sort(P, P + N, comp);

    return;
}

void output() {
    for (int i = 0; i < N; ++i)
        cout << P[i] << ' ';
    cout << '\n';
    return;
}

bool comp(int x, int y) {
    return pref[x][y];
}
