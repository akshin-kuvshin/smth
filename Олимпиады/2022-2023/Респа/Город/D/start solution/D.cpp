#include <iostream>
using namespace std;

typedef long long int lli;

const lli N_max = 100000LL;

lli N,
    A[N_max + 5LL],
    B[N_max + 5LL],
    A_sum[N_max + 5LL],
    B_sum[N_max + 5LL];
lli answer;

void input();
void solution();
void output();

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    input();
    solution();
    output();
    
    return 0;
}

void input() {
    cin >> N;
    for (int i = 0; i < (int)N; ++i)
        cin >> A[i];
    for (int i = 0; i < (int)N; ++i)
        cin >> B[i];
    return;
}

void solution() {
    for (int i = 0; i < N; ++i) {
        A_sum[i + 1] = A_sum[i] + A[i];
        B_sum[i + 1] = B_sum[i] + B[i];
    }

    for (lli l = 0LL; l < N; ++l)
        for (lli r = l; r < N; ++r)
            if ((A_sum[r + 1] - A_sum[l]) % (B_sum[r + 1] - B_sum[l]) == 0)
                ++answer;
    return;
}

void output() {
    cout << answer << '\n';
    return;
}
