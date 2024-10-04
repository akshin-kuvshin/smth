// author: Danila "akshin_" Axyonov

#include <iostream>
#include <algorithm>
using namespace std;
typedef long long int lli;

#define plli                pair<lli, lli>
#define mp(_first, _second) make_pair(_first, _second)
#define pb(_elem)           push_back(_elem)

const lli MAX_SIZE = (lli)1e5 + 5LL,
          len = 330LL,
          INF = (lli)1e18 + 1LL;

lli N,
    A[MAX_SIZE],
    B[len];
lli Q,
    l,
    r;

void solve();
lli get_max(lli, lli);

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    solve();
    
    return 0;
}

void solve() {
    fill(B, B + len, -INF);

    cin >> N;
    for (int i = 0; i < (int)N; ++i) {
        cin >> A[i];
        B[i / len] = max(B[i / len], A[i]);
    }

    cin >> Q;
    while (Q--) {
        cin >> l >> r;
        cout << get_max(--l, r) << ' ';
    }
    cout << '\n';
    
    return;
}

lli get_max(lli _l, lli _r) {
    lli m = -INF;
    lli ind = _l;
    while (ind < _r) {
        if (ind % len == 0LL and ind + len <= _r) {
            m = max(m, B[ind / len]);
            ind += len;
        } else
            m = max(m, A[ind++]);
    }
    return m;
}
