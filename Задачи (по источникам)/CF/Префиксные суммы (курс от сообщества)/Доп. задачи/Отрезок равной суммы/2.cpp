#include <iostream>
#include <array>
#include <algorithm>
#define data first
#define index second
using namespace std;

using lli = long long int;

const int N_max = 1e6;

int N;
array<lli, N_max + 5> A,
                      A_sum,
                      B,
                      B_sum;
array<pair<lli, int>, N_max + 5> d;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N;
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
        A_sum[i + 1] = A_sum[i] + A[i];
    }
    for (int i = 0; i < N; ++i) {
        cin >> B[i];
        B_sum[i + 1] = B_sum[i] + B[i];
    }

    for (int i = 0; i <= N; ++i)
        d[i] = make_pair(A_sum[i] - B_sum[i], i);
    
    sort(d.begin(), d.begin() + N + 1);

    for (int i = 0; i < N; ++i)
        if (d[i].data == d[i + 1].data) {
            cout << d[i].index + 1 << ' ' << d[i + 1].index << '\n';
            return 0;
        }
    
    cout << -1 << '\n';
    return 0;
}
