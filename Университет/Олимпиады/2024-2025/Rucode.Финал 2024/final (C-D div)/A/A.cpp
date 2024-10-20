// author: Danila "akshin_" Axyonov

#include <iostream>
#include <cmath>
using namespace std;
typedef long long int lli;


lli N,
    cur,
    ans = 1LL;

void solve();
lli len(lli);
lli _pow(lli, lli);

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}

void solve() {
    cin >> N;

    cur = 10LL;
    while (cur <= N) {
        lli _next = cur + 500LL;
        if (len(_next) != len(cur))
            _next = _pow(10LL, len(cur));
        cur = _next;
        ++ans;
    }
    cout << ans << '\n';

    return;
}

lli len(lli num) {
    lli res = 0LL;
    while (num) {
        ++res;
        num /= 10LL;
    }
    return res;
}

lli _pow(lli base, lli ptr) {
    lli res = 1LL;
    while (ptr--)
        res *= base;
    return res;
}
