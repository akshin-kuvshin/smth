// author: Danila "akshin_" Axyonov

#include <iostream>
using namespace std;
using lli = long long int;

#define plli                pair<lli, lli>
#define mp(_first, _second) make_pair(_first, _second)
#define pb(_elem)           push_back(_elem)

void solve();

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    solve();
    
    return 0;
}

void solve() {
    lli i,
        j;
    cin >> i >> j;
    lli n = 1LL;

    lli ans = 0LL;
    while (i or j) {
        if (i % 2LL != j % 2LL)
            ans += n;
        i /= 2LL;
        j /= 2LL;
        n *= 2LL;
    }

    cout << ans << '\n';
    return;
}
