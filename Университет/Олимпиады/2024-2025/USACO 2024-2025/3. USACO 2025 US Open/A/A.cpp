// author: Danila "akshin_" Axyonov
// ПАПОЧКА ДЖОН додумался развернуть строку и жёстко ЗАРЕШАЛ!!!

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
using lli = long long int;

#define plli                pair<lli, lli>
#define mp(_first, _second) make_pair(_first, _second)
#define pb(_elem)           push_back(_elem)

const lli MAX_SIZE = (lli)1e6 + 5LL,
          MOD = (lli)1e9 + 7LL;
lli fact_cache[MAX_SIZE] = {1LL};

void solve();

lli fact(lli n);
lli mod_pow(lli base, lli ptr);
lli rev(lli a); // reverse number by MOD (global defined value)
lli c(lli n, lli k);

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    solve();
    
    return 0;
}

void solve() {
    lli k,
        n,
        l;
    cin >> k >> n >> l;
    string t;
    cin >> t;

    lli ans = 1LL;

    reverse(t.begin(), t.end());
    lli O_cnt = 0LL;
    for (char ti : t) {
        if (ti == 'O')
            ++O_cnt;
        else { // ti == 'M'
            ans = (ans * c(O_cnt, k)) % MOD;
            O_cnt -= k;
        }
    }

    ans = mod_pow(ans, l);
    cout << ans << '\n';    
    return;
}

lli fact(lli n) {
    if (not fact_cache[n])
        fact_cache[n] = (n * fact(n - 1LL)) % MOD;
    return fact_cache[n];
}

lli mod_pow(lli base, lli ptr) {
    if (ptr == 0LL)
        return 1LL;
    if (ptr & 1LL)
        return (base * mod_pow(base, ptr - 1LL)) % MOD;
    // now (ptr) is positive even integer.
    lli half = mod_pow(base, ptr / 2LL);
    return (half * half) % MOD;
}

lli rev(lli a) {
    return mod_pow(a, MOD - 2LL);
}

lli c(lli n, lli k) {
    lli res = fact(n);
    res = (res * rev(fact(k))) % MOD;
    res = (res * rev(fact(n - k))) % MOD;
    return res;
}
