// author: Danila "akshin_" Axyonov

#include <iostream>
#include <algorithm>
using namespace std;
typedef long long int lli;

#define plli                pair<lli, lli>
#define mp(_first, _second) make_pair(_first, _second)
#define pb(_elem)           push_back(_elem)

const lli MAX_SIZE = (lli)2e5 + 5LL,
          len = 450LL,
          INF = (lli)1e18 + 1LL;

lli N,
    K,
    A[MAX_SIZE],
    B[len],
    op[len];
lli Q,
    l,
    r;
lli m;

void solve();
lli get_min(lli, lli);
void decrement(lli, lli);

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    solve();
    
    return 0;
}

void solve() {
    cin >> N >> K;
    fill(A, A + N, K);
    fill(B, B + len, K);

    cin >> Q;
    while (Q--) {
        cin >> l >> r;
        m = get_min(l, r);
        if (m == 0LL)
            cout << "0\n";
        else {
            decrement(l, r);
            cout << "1\n";
        }
    }
    
    return;
}

lli get_min(lli _l, lli _r) {
    lli _min = INF,
        ind = _l;
    
    while (ind < _r)
        if (ind % len == 0LL and ind + len <= _r) {
            _min = min(_min, B[ind / len]);
            ind += len;
        } else {
            _min = min(_min, A[ind] + op[ind / len]);
            ++ind;
        }
    
    return _min;
}

void decrement(lli _l, lli _r) {
    lli ind = _l;

    while (ind < _r) {
        if (ind % len == 0LL and ind + len <= _r) {
            --op[ind / len];
            --B[ind / len];
            ind += len;
        } else {
            --A[ind];
            B[ind / len] = min(B[ind / len], A[ind] + op[ind / len]);
            ++ind;
        }
    }

    return;
}
