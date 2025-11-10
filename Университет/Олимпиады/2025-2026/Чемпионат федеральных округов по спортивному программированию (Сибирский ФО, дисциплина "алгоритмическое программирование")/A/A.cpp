// author: Danila "akshin_" Axyonov

#include <iostream>
using namespace std;
typedef long long int lli;

#define mp(arg1, arg2)      make_pair(arg1, arg2)
#define pb(arg)             push_back(arg)

void solve();

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}

void solve() {
    lli k;
    cin >> k;

    lli ans = min(k, 4LL) + 4LL * min(k, 3LL) + 6LL * min(k, 2LL);
    ans += min(11LL * k - ans, 7LL);
    cout << ans << '\n';

    return;
}

