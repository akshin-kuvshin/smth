// author: Danila "akshin_" Axyonov

// [10/20 TESTS ACCEPTED]

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
using lli = long long int;

#define plli                pair<lli, lli>
#define mp(_first, _second) make_pair(_first, _second)
#define pb(_elem)           push_back(_elem)

const lli MOD = 1'000'000'007LL;

void solve();

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    solve();
    
    return 0;
}

void solve() {
    lli n,
        d;
    cin >> n >> d;
    lli a,
        b;
    cin >> a >> b;
    vector<lli> m(n);
    for (lli& mi : m)
        cin >> mi;
    
    lli ans = 0LL;
    
    sort(m.begin(), m.end(), greater<lli>());
    for (int i = 0; i < (int)a; ++i)
        m[i] += d;
    for (int i = (int)a; i < (int)n; ++i)
        ans = (ans + (m[i] * m[i]) % MOD) % MOD;
    


    lli s = 0LL;
    for (int i = 0; i < (int)a; ++i)
        s += m[i];
    s -= b * d;
    
    lli e = a;
    while (b < e and m[e - 1LL] < s / e) { // в последнем < или <= ?
        --e;
        ans = (ans + (m[e] * m[e]) % MOD) % MOD;
        s -= m[e];
    }
    
    if (e == b)
        for (int i = 0; i < (int)e; ++i) {
            m[i] -= d;
            ans = (ans + (m[i] * m[i]) % MOD) % MOD;
        }
    else { // b < e
        lli _m = s / e,
            _c = s % e;
        lli _M = _m + 1LL;
        ans = (ans + (((_M * _M) % MOD) * _c) % MOD) % MOD;
        ans = (ans + (((_m * _m) % MOD) * (e - _c)) % MOD) % MOD;
    }



    cout << ans << '\n';
    return;
}
