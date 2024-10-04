// author: Danila "akshin_" Aksionov

#include <iostream>
#include <algorithm>
using namespace std;
typedef long long int lli;

const lli MAX_SIZE = 200000LL;

lli Q;
lli N,
    A[MAX_SIZE + 5LL];

void solve();

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> Q;
    while (Q--)
        solve();
    
    return 0;
}

void solve() {
    cin >> N;
    for (int i = 0; i < (int)N; ++i)
        cin >> A[i];
    
    sort(A, A + N);

    cout << max(A[0] * A[1], A[N - 2LL] * A[N - 1LL]) << '\n';
    return;
}
