// author: Danila "akshin_" Aksionov

#include <iostream>
using namespace std;
typedef long long int lli;

#define plli                pair<lli, lli>
#define mp(_first, _second) make_pair(_first, _second)
#define pb(_elem)           push_back(_elem)

void solve();
lli gcd_ext_R(lli, lli, lli&, lli&);

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    solve();
    
    return 0;
}

void solve() {
    lli a,
        b,
        c;
    cin >> a >> b >> c;

    lli x = 0LL,
        y = 0LL;
    lli d = gcd_ext_R(a, b, x, y);
    
    if (c % d != 0LL) {
        cout << "-1\n";
        return;
    }

    x *= c / d;
    y *= c / d;
    lli dx = b / d,
        dy = a / d;
    
    if (x < 0LL) {
        lli k = (-x + dx - 1LL) / dx;
        x += k * dx;
        y -= k * dy;
    } else {
        lli k = x / dx;
        x -= k * dx;
        y += k * dy;
    }

    cout << x << ' ' << y << '\n';
    return;
}

lli gcd_ext_R(lli a, lli b, lli &x, lli &y) {
    if (b == 0LL) {
        x = 1LL;
        y = 0LL;
        return a;
    }
    lli d = gcd_ext_R(b, a % b, x, y);
    x -= (a / b) * y;
    swap(x, y);
    return d;
}

