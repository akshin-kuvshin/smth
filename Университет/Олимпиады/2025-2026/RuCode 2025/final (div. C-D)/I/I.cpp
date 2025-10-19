// authors: Danila "akshin_" Axyonov & Stepan Evseev

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long int lli;

#define mp(_first, _second)     make_pair(_first, _second)
#define pb(_elem)               push_back(_elem)

vector<lli> primes;

void solve();
lli _pow(lli base, lli ptr);

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    vector<bool> is_prime(1987, true);
    for (int n = 2; n * n < 1987; ++n) {
        if (not is_prime[n])
            continue;
        for (int nn = n * n; nn < 1987; nn += n)
            is_prime[nn] = false;
    }
    for (int n = 2; n < 1987; ++n)
        if (is_prime[n])
            primes.pb((lli)n);

    lli Q;
    cin >> Q;
    while (Q--)
        solve();

    return 0;
}

void solve() {
    lli res;

    cout << "? 1" << endl;
    cin >> res;
    if (res != 0LL) {
        cout << "WATAFAK" << endl;
        abort();
    }

    lli ans = 1LL;
    for (lli p : primes) {
        res = 0LL;

        lli ptr = 0LL;
        while (ans * _pow(p, ptr + 1LL) <= 1986LL and res == 0LL) {
            ++ptr;
            cout << "? " << _pow(p, ptr) << endl;
            cin >> res;
        }
        if (res == 1LL)
            --ptr;

        ans *= _pow(p, ptr);
    }

    cout << "! " << ans << endl;
    return;
}

lli _pow(lli base, lli ptr) {
    if (ptr == 0LL)
        return 1LL;
    return base * _pow(base, ptr - 1LL);
}

