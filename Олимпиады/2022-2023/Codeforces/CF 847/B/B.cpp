#include <iostream>
#include <array>
using namespace std;

// Constants
const int N_max = 50;

// Variables
int t;
array<int, N_max + 5> A;
int n,
    s,
    r;
int _max;

// Functions
void input();
void solution();
void output();

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
    cin >> n >> s >> r;
    return;
}

void solution() {
    fill(A.begin(), A.end(), 0);

    A[0] = s - r;
    s -= A[0];

    int ind = 1;
    while (s) {
        if (ind) {
            ++A[ind];
            --s;
        }
        ind = (ind + 1) % n;
    }
    
    return;
}

void output() {
    for (int i = 0; i < n; ++i)
        cout << A[i] << ' ';
    cout << '\n';    
    return;
}
