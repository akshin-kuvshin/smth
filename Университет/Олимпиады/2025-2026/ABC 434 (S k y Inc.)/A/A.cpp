// author: Danila "akshin_" Axyonov

#include <iostream>
using namespace std;
using lli = long long int;
using plli = pair<lli, lli>;

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
    lli w,
        b;
    cin >> w >> b;
    lli ans = 1000LL * w / b + 1LL;
    cout << ans << '\n';
    return;
}
