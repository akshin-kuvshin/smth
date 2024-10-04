// author: Danila "akshin_" Axyonov
// FINAL VERSION

#include <iostream>
using namespace std;
typedef long long int lli;

#define plli                pair<lli, lli>
#define mp(_first, _second) make_pair(_first, _second)
#define pb(_elem)           push_back(_elem)

lli a,
    c,
    n;
lli ans;

void solve();

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    solve();
    
    return 0;
}

void solve() {
    cin >> a >> c >> n;

    ans = n;
    n %= (a + 1LL + c);
    if (n < a + 1LL)
        ans += a + 1LL - n;
    
    cout << ans << '\n';
    return;
}
