// author: Danila "akshin_" Axyonov

#include <iostream>
using namespace std;
typedef long long int lli;

#define plli                pair<lli, lli>
#define mp(_first, _second) make_pair(_first, _second)
#define pb(_elem)           push_back(_elem)

#define val                 first
#define cnt                 second

void solve();
plli bs(lli, lli, lli);

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
        k;
    cin >> n >> k;
    cout << bs(1LL, n, k).val << '\n';    
    return;
}

plli bs(lli l, lli r, lli k) {
    lli len = r - l + 1LL;
    if (len < k) return mp(0LL, 0LL);
    if (len == 1LL) return mp(l, 1LL);
    lli m = (l + r) >> 1,
        d = m - l + 1LL;
    if (len & 1LL) {
        plli x = bs(l, m - 1LL, k);
        return mp(x.val + m + (x.val + d * x.cnt), 2LL * x.cnt + 1LL);
    }
    plli x = bs(l, m, k);
    return mp(x.val + (x.val + d * x.cnt), 2LL * x.cnt);
}
