// author: Danila "akshin_" Axyonov

#include <iostream>
using namespace std;
typedef long long int lli;

void solve();

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
    lli a,
        b;
    cin >> a >> b;
    
    lli ans;
    if (a % 2LL == 0LL and b % 2LL == 0LL)
        ans = a * b / 2LL + 2LL;
    else if (a % 2LL == 0LL and b % 2LL == 1LL)
        ans = -1LL;
    else if (a % 2LL == 1LL and b % 2LL == 0LL) {
        if (b % 4LL != 0LL)
            ans = -1LL;
        else // b % 4LL == 0LL
            ans = a * b / 2LL + 2LL;
    } else // a % 2 == 1LL and b % 2LL == 1LL
        ans = a * b + 1LL;
    cout << ans << '\n';
    
    return;
}

