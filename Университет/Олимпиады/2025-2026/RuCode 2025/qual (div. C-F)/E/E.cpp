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
        m;
    cin >> n >> m;

    if (n * (n - 1LL) / 2LL < m) {
        cout << "-1\n";
        return;
    }

    cout << max(n - m, 1LL) << ' ';

    for (lli d = 0LL; ; ++d)
        if (d * (d - 1LL) / 2LL >= m) {
            cout << min(n - d + 1LL, n) << '\n';
            break;
        }
    
    return;
}
