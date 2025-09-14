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
    lli n;
    cin >> n;
    for (int _ = 0; _ < (int)n; ++_) {
        lli ai;
        cin >> ai;
        cout << (n - ai + 1LL) << ' ';
    }
    cout << '\n';
    return;
}

