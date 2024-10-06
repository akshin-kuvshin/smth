// author: Danila "akshin_" Axyonov

#include <iostream>
#include <algorithm>
using namespace std;
typedef long long int lli;

#define plli                pair<lli, lli>
#define mp(_first, _second) make_pair(_first, _second)
#define pb(_elem)           push_back(_elem)

const lli MAX_SIZE = 100005LL,
          INF = 1000000000000000001LL;

lli Q;
lli N,
    D,
    K,
    L[MAX_SIZE],
    R[MAX_SIZE];
lli bro_day = -1LL,
    _max = -INF,
    mom_day = -1LL,
    _min = INF;

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
    bro_day = mom_day = -1LL;
    _max = -INF;
    _min = INF;

    cin >> N >> D >> K;
    fill(L, L + N, 0LL);
    fill(R, R + N, 0LL);
    for (int i = 0; i < (int)K; ++i) {
        int _l,
            _r;
        cin >> _l >> _r;
        --_l;
        ++L[_l];
        ++R[_r];
    }

    lli b = 0LL,
        e = D - 1LL;
    lli cnt = 0LL;
    for (int i = 0; i < (int)D; ++i)
        cnt += L[i] - R[i];
    while (e < N) {
        if (_max < cnt) {
            bro_day = b;
            _max = cnt;
        }
        if (cnt < _min) {
            mom_day = b;
            _min = cnt;
        }
        ++b; ++e;
        cnt += L[e] - R[b];
    }
    
    cout << ++bro_day << ' ' << ++mom_day << '\n';
    return;
}
