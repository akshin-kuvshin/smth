// author: Danila "akshin_" Aksionov

#include <iostream>
#include <cmath>
using namespace std;
typedef long long int lli;

#define plli                pair<lli, lli>
#define mp(_first, _second) make_pair(_first, _second)
#define pb(_elem)           push_back(_elem)

lli a,
    b,
    c,
    d;
lli n,
    m,
    gcd;
lli ans;

void solve();
lli gcd_R(lli, lli);

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    solve();
    
    return 0;
}

void solve() {
    cin >> a >> b >> c >> d;

    n = abs(a - c);
    m = abs(b - d);
    gcd = gcd_R(n, m);
    n /= gcd;
    m /= gcd;

    ans = gcd * (n + m - 1LL);
    cout << ans << '\n';
    return;
}

lli gcd_R(lli x, lli y) {
    return ((x && y) ? gcd_R(y, x % y) : (x | y));
}
