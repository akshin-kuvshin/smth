// author: Danila "akshin_" Axyonov

#include <iostream>
using namespace std;
using lli = long long int;

const lli MOD = (lli)1e9 + 7LL;

void solve();
lli inv(lli a);
lli bin_pow(lli base, lli ptr);

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	solve();
	
	return 0;
}

void solve() {
    lli n,
        m;
    cin >> n >> m;
    
    lli ans = 0LL;
    for (lli x2 = 0LL; x2 * 2LL <= n; ++x2) {
        if ((n - x2 * 2LL) % 3LL)
            continue;
        lli x3 = (n - x2 * 2LL) / 3LL;
        if (x2 + x3 > m)
            continue;
        
        lli nn = n,
            xx2 = x2,
            xx3 = x3,
            res = 1LL;
        while (xx2--) {
            res *= nn * (nn - 1LL) / 2LL;
            res %= MOD;
            nn -= 2LL;
        }
        while (xx3--) {
            res *= nn * (nn - 1LL) * (nn - 2LL) / 6LL;
            res %= MOD;
            nn -= 3LL;
        }
        
        lli x = x2 + x3;
        lli Amx = 1LL;
        for (lli k = m - x + 1LL; k <= m; ++k) {
            Amx *= k;
            Amx %= MOD;
        }
        res *= Amx;
        res %= MOD;
        
        for (lli k = 2LL; k <= x2; ++k) {
            res *= inv(k);
            res %= MOD;
        }
        for (lli k = 2LL; k <= x3; ++k) {
            res *= inv(k);
            res %= MOD;
        }
        
        ans += res;
        ans %= MOD;
    }
    
    cout << ans << '\n';
	return;
}

lli inv(lli a) {
    return bin_pow(a, MOD - 2LL);
}

lli bin_pow(lli base, lli ptr) {
    if (not ptr)
        return 1LL;
    if (ptr & 1LL)
        return (base * bin_pow(base, ptr - 1LL)) % MOD;
    lli half = bin_pow(base, ptr >> 1);
    return (half * half) % MOD;
}
