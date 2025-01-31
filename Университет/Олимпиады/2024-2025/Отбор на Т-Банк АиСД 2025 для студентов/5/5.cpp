// author: Danila "akshin_" Axyonov

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
using lli = long long int;

#define plli                pair<lli, lli>
#define mp(_first, _second) make_pair(_first, _second)
#define pb(_elem)           push_back(_elem)

void solve();
lli bs(lli a, lli b);
lli f(lli y, lli a, lli b);

lli x_size;
vector<lli> x,
            pref,
            suf;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    solve();
    
    return 0;
}

void solve() {
    cin >> x_size;
    x.resize(x_size);
    for (int i = 0; i < (int)x_size; ++i)
        cin >> x[i];
    sort(x.begin(), x.end());
    
    pref.resize(x_size);
    pref.front() = x.front();
    for (int i = 1; i < (int)x_size; ++i)
        pref[i] = pref[i - 1] + x[i];
    suf.resize(x_size);
    suf.back() = x.back();
    for (int i = (int)x_size - 2; i >= 0; --i)
        suf[i] = suf[i + 1] + x[i];
    
    lli q;
    cin >> q;
    while (q--) {
        lli a,
            b;
        cin >> a >> b;
        cout << bs(a, b) << '\n';
    }
    
    return;
}

lli bs(lli a, lli b) {
    lli yl = x.front(),
        yr = x.back();
    while (yl + 2LL < yr) {
        lli d = (yr - yl) / 3LL;
        lli ym1 = yl + d,
            ym2 = yr - d;
        if (f(ym1, a, b) < f(ym2, a, b))
            yr = ym2;
        else
            yl = ym1;
    }

    vector<lli> y;
    for (lli _y = yl; _y <= yr; ++_y)
        y.pb(_y);
    lli res = f(y[0], a, b);
    for (lli _y : y)
        res = min(res, f(_y, a, b));
    return res;
}

lli f(lli y, lli a, lli b) {
    lli l = 0LL,
        r = x_size;
    while (l + 1LL < r) {
        lli m = (l + r) >> 1;
        if (x[m] <= y)
            l = m;
        else
            r = m;
    }

    lli res = ((l + 1LL) * y - pref[l]) * a;
    if (r < x_size)
        res += (suf[r] - (x_size - r) * y) * b;
    return res;
}
