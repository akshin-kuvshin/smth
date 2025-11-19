// author: Danila "akshin_" Axyonov

#include <iostream>
using namespace std;
typedef long long int lli;

#define mp(arg1, arg2)      make_pair(arg1, arg2)
#define pb(arg)             push_back(arg)

void solve();

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}

void solve() {
    lli c,
        v,
        l,
        r;
    cin >> c >> v >> l >> r;

    lli A_to_A_mod_2 = 0LL;
    if (l == 1LL) {
        ++A_to_A_mod_2;
        ++l;

        if (l > r) {
            cout << "King\n";
            return;
        }
    }
    if (l == 2LL) {
        ++l;
        if (l > r) {
            cout << (A_to_A_mod_2 & 1LL ? "King" : "Queen") << '\n';
            return;
        }
    }
    if (l == 3LL) {
        A_to_A_mod_2 = (A_to_A_mod_2 + c) & 1LL;
        l += 2LL;

        if (l > r) {
            cout << (A_to_A_mod_2 & 1LL ? "King" : "Queen") << '\n';
            return;
        }
    }
    
    lli odd_from_l_to_r = (r - l + 1LL) >> 1;
    if ((r - l + 1LL) & 1LL and l & 1LL)
        ++odd_from_l_to_r;
    A_to_A_mod_2 = (A_to_A_mod_2 + (odd_from_l_to_r & 1LL) * (c & 1LL) * (v & 1LL)) & 1LL;
    cout << (A_to_A_mod_2 & 1LL ? "King" : "Queen") << '\n';

    return;
}

