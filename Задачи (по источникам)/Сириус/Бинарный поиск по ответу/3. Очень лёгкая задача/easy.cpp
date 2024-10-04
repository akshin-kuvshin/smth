// author: Danila "akshin_" Aksionov

#include <iostream>
using namespace std;
typedef long long int lli;

#define plli                pair<lli, lli>
#define mp(_first, _second) make_pair(_first, _second)
#define pb(_elem)           push_back(_elem)

lli N,
    x,
    y;
lli ans;

void solve();
bool f(lli);
lli bs();

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    solve();
    
    return 0;
}

void solve() {
    cin >> N >> x >> y;
    ans = bs();
    cout << ans << '\n';
    return;
}

bool f(lli t) {
    if (t < min(x, y))
        return false;
    
    t -= min(x, y);
    return (1LL + t / x + t / y >= N);
}

lli bs() {
    lli l = 0LL,
        r = (lli)1e10;
    while (l + 1LL < r) {
        lli mid = (l + r) >> 1;
        if (f(mid))
            r = mid;
        else
            l = mid;
    }
    return r;
}
