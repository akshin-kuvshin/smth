// author: Danila "akshin_" Axyonov

#include <iostream>
#include <algorithm>
using namespace std;
typedef long long int lli;

#define plli                pair<lli, lli>
#define mp(_first, _second) make_pair(_first, _second)
#define pb(_elem)           push_back(_elem)

const lli MAX_SIZE = 100005LL;

lli Q;
lli N,
    D,
    K,
    L[MAX_SIZE],
    R[MAX_SIZE];
lli bro_day,
    mom_day;

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

    // TODO
    
    return;
}
