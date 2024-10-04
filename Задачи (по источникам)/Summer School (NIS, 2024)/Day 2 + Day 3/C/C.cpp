// author: Danila "akshin_" Axyonov

#include <iostream>
using namespace std;
typedef long long int lli;

#define plli                pair<lli, lli>
#define mp(_first, _second) make_pair(_first, _second)
#define pb(_elem)           push_back(_elem)

lli _left,
    _right;
lli xl,
    xr;
lli l,
    r,
    mid;
lli ans;

void solve();

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    solve();
    
    return 0;
}

void solve() {
    cin >> _left >> _right;

    l = 0LL;
    r = (lli)1e9;
    while (l + 1LL < r) {
        mid = (l + r) >> 1;
        if (mid * (mid + 1LL) < _left)
            l = mid;
        else // mid * (mid + 1LL) < _left
            r = mid;
    }
    xl = r;

    l = 0LL;
    r = (lli)1e9;
    while (l + 1LL < r) {
        mid = (l + r) >> 1;
        if (mid * (mid + 1LL) <= _right)
            l = mid;
        else // mid * (mid + 1LL) <= _right
            r = mid;
    }
    xr = l;

    ans = xr - xl + 1LL;
    cout << ans << '\n';
    return;
}
