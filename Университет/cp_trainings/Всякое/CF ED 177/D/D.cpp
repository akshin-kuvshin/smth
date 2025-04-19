// author: Danila "akshin_" Axyonov

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
using lli = long long int;

#define plli                pair<lli, lli>
#define mp(_first, _second) make_pair(_first, _second)
#define pb(_elem)           push_back(_elem)

const lli MOD = 998'244'353LL,
          N = 26LL,
          LEN_MAX = (lli)5e5 + 5LL;

lli fact[LEN_MAX];

void solve();
lli inv(lli a);
lli _pow(lli base, lli ptr);

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    fact[0] = 1LL;
    for (lli i = 1LL; i < LEN_MAX; ++i)
        fact[i] = (fact[i - 1LL] * i) % MOD;
    
    lli Q;
    cin >> Q;
    while (Q--)
        solve();
    
    return 0;
}

void solve() {
    vector<lli> c(N);
    lli len = 0LL;
    for (lli& ci : c) {
        cin >> ci;
        len += ci;
    }
    
    vector<vector<lli>> dp(len + 1LL, vector<lli>(N, 0LL));
    dp[0][0] = 1LL; dp[c[0]][0] = 1LL;
    for (int j = 1; j < (int)N; ++j)
        for (int i = 0; i <= (int)len; ++i) {
            dp[i][j] = dp[i][j - 1];
            if (c[j] and (lli)i - c[j] >= 0LL) {
                dp[i][j] += dp[(lli)i - c[j]][j - 1];
                dp[i][j] %= MOD;
            }
        }
    
    lli ans = dp[len >> 1].back();
    ans *= fact[len >> 1];
    ans %= MOD;
    ans *= fact[(len + 1LL) >> 1];
    ans %= MOD;

    lli denom = 1LL;
    for (lli ci : c) {
        denom *= fact[ci];
        denom %= MOD;
    }

    ans *= inv(denom);
    ans %= MOD;

    cout << ans << '\n';
    return;
}

lli inv(lli a) {
    return _pow(a, MOD - 2LL);
}

lli _pow(lli base, lli ptr) {
    if (not ptr)
        return 1LL;
    if (ptr & 1LL)
        return (base * _pow(base, ptr - 1LL)) % MOD;
    lli half = _pow(base, ptr >> 1);
    return (half * half) % MOD;
}
