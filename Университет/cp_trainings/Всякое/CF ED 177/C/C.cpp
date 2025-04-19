// author: Danila "akshin_" Axyonov

#include <iostream>
#include <vector>
using namespace std;
using lli = long long int;

#define plli                pair<lli, lli>
#define mp(_first, _second) make_pair(_first, _second)
#define pb(_elem)           push_back(_elem)

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
    vector<lli> a(n);
    for (int i = 0; i < (int)n; ++i) {
        cin >> a[i];
        --a[i];
    }
    
    vector<bool> used(n);
    lli ans = 0LL;
    while (n--) {
        lli di;
        cin >> di;
        --di;

        if (used[di]) {
            cout << ans << ' ';
            continue;
        }

        lli was = a[di];
        a[di] = di;
        used[di] = true;
        lli dans = 0LL;
        while (was != di) {
            ++dans;

            di = was;
            was = a[di];
            a[di] = di;
            used[di] = true;
        }
        dans = max(dans, 1LL);
        ans += dans;

        cout << ans << ' ';
    }
    cout << '\n';
    
    return;
}
