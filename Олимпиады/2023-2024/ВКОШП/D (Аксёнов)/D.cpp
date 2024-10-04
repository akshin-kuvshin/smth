#include <iostream>
#include <unordered_map>
using namespace std;
typedef long long int lli;
typedef pair<lli, lli> plli;

const lli MAX_SIZE = (lli)5e3 + 1LL,
          MOD = (lli)1e9 + 7LL;

lli N;
lli ans;
lli fact[MAX_SIZE];

lli modpow(lli base, lli ptr) {
    if (ptr == 0LL)
        return 1LL;
    if (ptr % 2LL == 0LL) {
        lli half = modpow(base, ptr / 2LL);
        return (half * half) % MOD;
    }
    return (base * modpow(base, ptr - 1LL)) % MOD;
}

unordered_map<lli, lli> S;
lli _div(lli a, lli b) {
    if (S[a] == 0LL)
        S[a] = modpow(a, MOD - 2LL);
    lli x = S[a];
    return (x * b) % MOD;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    fact[0] = 1LL;
    for (lli i = 1LL; i < MAX_SIZE; ++i)
        fact[i] = (i * fact[i - 1LL]) % MOD;

    cin >> N;

    ans = 1LL;
    for (lli i = 1LL; i < N; ++i) {
        lli tmp_ans = 0LL;
        for (lli zero = 0LL; zero <= i; ++zero) {
            lli ost = i - zero;
            lli one = 2LL * ost - i - 1LL;
            lli two = ost - one;

            if (one < 0LL)
                break;

            lli t = fact[i];
            t = _div(fact[zero], t);
            t = _div(fact[one], t);
            t = _div(fact[two], t);
            tmp_ans = (tmp_ans + t) % MOD;
        }
        ans = (ans * tmp_ans) % MOD;
    }

    cout << ans << '\n';
    return 0;
}
