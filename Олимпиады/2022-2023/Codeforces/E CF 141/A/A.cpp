#include <iostream>
#include <array>
#include <algorithm>
using namespace std;

// Constants
const int N_max = 50;

// Variables
int tests_number;

int N;
array<int, N_max + 5> A;

// Functions
void input();
void solution();
bool comp(int, int);
bool is_all_equal();

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin >> tests_number;
    for (int _t = 0; _t < tests_number; ++_t) {
        input();
        solution();
    }

    return 0;
}

void input() {
    cin >> N;
    for (int i = 0; i < N; ++i)
        cin >> A[i];    
    return;
}

void solution() {
    if (is_all_equal()) {
        cout << "NO\n";
        return;
    }

    sort(A.begin(), A.begin() + N, comp);

    cout << "YES\n";

    if (A[0] == A[1]) {
        cout << A[N - 1] << ' ';
        --N;
    }

    for (int i = 0; i < N; ++i)
        cout << A[i] << ' ';
    cout << '\n';
    return;
}

bool comp(int x, int y) {
    return x > y;
}

bool is_all_equal() {
    for (int i = 0; i < N - 1; ++i)
        if (A[i] != A[i + 1])
            return false;
    return true;
}
