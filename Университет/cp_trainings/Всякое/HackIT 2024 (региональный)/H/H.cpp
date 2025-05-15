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
    lli n;
    cin >> n;
    --n;
    lli k,
        prev, // имеем право оставить без определения.
        ans = 0LL;
    for (k = 1LL; k * k <= n; ++k) {
        lli d = n / k;
        ans += d + (k - 1LL) * (prev - d);
        prev = d;
    }
    while (k <= n and k <= prev) {
        lli d = n / k;
        ans += d;
        ++k;
    }
    cout << ans << '\n';
    return;
}
