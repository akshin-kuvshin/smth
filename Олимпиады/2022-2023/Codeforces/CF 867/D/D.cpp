// author: Danila "akshin_" Aksionov

#include <iostream>
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
    
    if (N == 1LL)
        cout << "1\n";
    else if (N & 1LL)
        cout << "-1\n";
    else {
        A[0] = N;
        for (int i = 1; i <= N / 2LL; ++i) {
            if (i & 1LL) {
                A[i] = N - i;
                A[N - i] = i;
            } else {
                A[i] = i;
                A[N - i] = N - i;
            }
        }

        for (int i = 0; i < (int)N; ++i)
            cout << A[i] << ' ';
        cout << '\n';
    }

    return;
}
