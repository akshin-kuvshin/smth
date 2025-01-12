// author: Danila "akshin_" Axyonov
// Сложнейшая задача контеста. Затуп длиною в час... ~плачущий смайлик~

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
using lli = long long int;

#define plli                pair<lli, lli>
#define mp(_first, _second) make_pair(_first, _second)
#define pb(_elem)           push_back(_elem)

const lli INF = (lli)1e18 + 1LL;

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
    vector<plli> x(n);
    for (int i = 0; i < (int)n; ++i)
        cin >> x[i].first;
    for (int i = 0; i < (int)n; ++i)
        cin >> x[i].second;
    
    lli cnt = 0LL,
        d;
    for (int i = 0; i < (int)n; ++i)
        if (x[i].first - x[i].second < 0LL) {
            ++cnt;
            d = x[i].second - x[i].first;
        }
    
    if (cnt == 0LL) {
        cout << "YES\n";
        return;
    } else if (cnt > 1LL) {
        cout << "NO\n";
        return;
    }
    // now cnt == 1LL
    for (int i = 0; i < (int)n; ++i) {
        if (x[i].first - x[i].second < 0LL)
            continue;
        if (x[i].first - d - x[i].second < 0LL) {
            cout << "NO\n";
            return;
        }
    }
    cout << "YES\n";
    return;
}
