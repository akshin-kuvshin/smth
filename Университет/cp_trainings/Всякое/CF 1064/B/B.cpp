// author: Danila "akshin_" Axyonov

#include <iostream>
typedef long long int lli;
using namespace std;

void solve();

int main() {
    int q;
    cin >> q;
    while (q--)
        solve();
    return 0;
}

void solve() {
    lli a,
        b,
        n;
    cin >> a >> b >> n;

    lli ans = 1LL;
    if (b < a and a < b * n)
        ++ans;
    cout << ans << '\n';
}
