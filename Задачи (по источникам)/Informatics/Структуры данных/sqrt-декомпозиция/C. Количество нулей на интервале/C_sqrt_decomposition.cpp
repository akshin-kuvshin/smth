// author: Danila "akshin_" Axyonov

#include <iostream>
#include <algorithm>
using namespace std;
typedef long long int lli;

#define plli                pair<lli, lli>
#define mp(_first, _second) make_pair(_first, _second)
#define pb(_elem)           push_back(_elem)

const lli MAX_SIZE = (lli)1e5 + 5LL,
          len = 330LL;

lli N,
    A[MAX_SIZE],
    B[len];
lli Q;

void solve();
lli get_zeros_number(lli, lli);

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
        B[i / len] += (A[i] == 0LL ? 1LL : 0LL);
    }

    cin >> Q;
    while (Q--) {
        lli l, r;
        cin >> l >> r;
        cout << get_zeros_number(--l, r) << ' ';
    }
    cout << '\n';
    
    return;
}

lli get_zeros_number(lli l, lli r) {
    lli ans = 0LL;
    lli ind = l;
    while (ind < r) {
        if (ind % len == 0LL and ind + len <= r) {
            ans += B[ind / len];
            ind += len;
        } else
            ans += (A[ind++] == 0LL ? 1LL : 0LL);
    }
    return ans;
}
