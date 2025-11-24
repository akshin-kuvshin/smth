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
    lli n,
        k;
    cin >> n >> k;

    if (k == 0LL) {
        cout << ((n == 1LL) ? "YES" : "NO") << '\n';
        return;
    }

    lli cnt = 0LL;
    for (lli d = 2LL; d <= n; ++d)
        while (n % d == 0LL) {
            n /= d;
            ++cnt;
        }
    
    cout << ((cnt >= k) ? "YES" : "NO") << '\n';
    return;
}
