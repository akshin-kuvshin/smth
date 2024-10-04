// author: Danila "akshin_" Aksionov

#include <iostream>
using namespace std;
typedef long long int lli;

#define plli                pair<lli, lli>
#define mp(_first, _second) make_pair(_first, _second)
#define pb(_elem)           push_back(_elem)

const lli MAX_SIZE = (lli)2e5 + 5LL;

lli N,
    A[MAX_SIZE],
    _sum;

void solve();

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    solve();
    
    return 0;
}

void solve() {
    cin >> N;
    for (int i = 0; i < (int)N; ++i) {
        cin >> A[i];

        if (!A[i]) {
            cout << "0\n";
            return;
        }

        _sum += max(A[i] - 1LL, 0LL);
    }
    cout << ++_sum << '\n';
    return;
}
