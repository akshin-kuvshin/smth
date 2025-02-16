// author: Danila "akshin_" Axyonov

#include <iostream>
#include <string>
using namespace std;
using lli = long long int;

#define plli                pair<lli, lli>
#define mp(_first, _second) make_pair(_first, _second)
#define pb(_elem)           push_back(_elem)

void solve();
lli s(lli, lli, lli);
lli l(lli, lli, lli);
lli r(lli, lli, lli);
lli u(lli, lli, lli);
lli d(lli, lli, lli);

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    lli Q;
    cin >> Q;
    while (Q--)
        solve();
    
    return 0;
}

void solve() {
    lli n,
        m;
    cin >> n >> m;

    lli _l,
        _r,
        _m;
    string ans;
    lli diff;
    
    // vertical
    _l = 0LL;
    _r = m;
    while (_l + 1LL < _r) {
        _m = (_l + _r) >> 1;
        if (r(n, m, _m) - l(n, m, _m) >= 0LL)
            _l = _m;
        else // r(n, m, _m) - l(n, m, _m) < 0LL
            _r = _m;
    }
    if (abs(r(n, m, _l) - l(n, m, _l)) <= abs(r(n, m, _r) - l(n, m, _r))) {
        ans = "V " + to_string(_l + 1LL);
        diff = abs(r(n, m, _l) - l(n, m, _l));
    } else { // abs(r(n, m, _l) - l(n, m, _l)) > abs(r(n, m, _r) - l(n, m, _r))
        ans = "V " + to_string(_r + 1LL);
        diff = abs(r(n, m, _r) - l(n, m, _r));
    }

    // horizontal
    _l = 0LL;
    _r = n;
    while (_l + 1LL < _r) {
        _m = (_l + _r) >> 1;
        if (d(n, m, _m) - u(n, m, _m) >= 0LL)
            _l = _m;
        else // d(n, m, _m) - u(n, m, _m) < 0LL
            _r = _m;
    }
    if (abs(d(n, m, _l) - u(n, m, _l)) < diff) {
        ans = "H " + to_string(_l + 1LL);
        diff = abs(d(n, m, _l) - u(n, m, _l));
    }
    if (abs(d(n, m, _r) - u(n, m, _r)) < diff) {
        ans = "H " + to_string(_r + 1LL);
        diff = abs(d(n, m, _r) - u(n, m, _r));
    }
    
    cout << ans << '\n';
    return;
}

lli s(lli _a, lli _d, lli _n) {
    return ((2LL * _a + (_n - 1LL) * _d) * _n) / 2LL;;
}

lli l(lli n, lli m, lli _r) {
    lli res = s(1LL, m, n);
    res = s(res, n, _r);
    return res;
}

lli r(lli n, lli m, lli _l) {
    lli res = s(1LL, 1LL, n * m) - l(n, m, _l);
    return res;
}

lli u(lli n, lli m, lli _d) {
    lli res = s(1LL, 1LL, m);
    res = s(res, m * m, _d);
    return res;
}

lli d(lli n, lli m, lli _u) {
    lli res = s(1LL, 1LL, n * m) - u(n, m, _u);
    return res;
}
