// author: Danila "akshin_" Axyonov

// [14/20 TESTS ACCEPTED]

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
    reverse(m.begin(), m.begin() + a);
    for (int i = (int)a; i < (int)n; ++i)
        ans = (ans + (m[i] * m[i]) % MOD) % MOD;
    


    lli s = 0LL;
    for (int i = 0; i < (int)a; ++i)
        s += m[i];
    s += (a - b) * d;

    lli e = a;
    while (a - b < e and s / e < m[e - 1LL]) { // в последнем < или <= ?
        --e;
        ans = (ans + (m[e] * m[e]) % MOD) % MOD;
        s -= m[e];
    }

    if (a - b == e)
        for (int i = 0; i < (int)e; ++i) {
            m[i] += d;
            ans = (ans + (m[i] * m[i]) % MOD) % MOD;
        }
    else { // a - b < e
        lli _m = s / e;

        vector<lli> added(e);
        lli new_s = 0LL;
        for (int i = 0; i < (int)e; ++i) {
            lli diff = min(_m - m[i], d);
            m[i] += diff;
            added[i] = diff;
            new_s += m[i];
        }
        lli _c = s - new_s;
        for (int i = 0; i < (int)e and _c; ++i)
            if (added[i] != d) {
                ++m[i];
                --_c;
            }
        for (int i = 0; i < (int)e; ++i)
            ans = (ans + (m[i] * m[i]) % MOD) % MOD;
    }



    cout << ans << '\n';
    return;
}
