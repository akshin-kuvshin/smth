// author: Danila "akshin_" Axyonov

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
    lli n,
        m;
    cin >> n >> m;
    vector<lli> a(n);
    for (int i = 0; i < (int)n; ++i) {
        cin >> a[i];
        a[i] %= m;
    }
    sort(a.begin(), a.end());
    vector<lli> pref(n + 1LL);
    pref.front() = 0LL;
    for (int i = 0; i < (int)n; ++i)
        pref[i + 1] = pref[i] + a[i];

    lli ans = INF;
    for (auto x : a) {
        lli ops_number = 0LL;
        
        lli l = (lli)(lower_bound(a.begin(), a.end(), x) - a.begin());
        lli r = (lli)(upper_bound(a.begin(), a.end(), x + m / 2LL) - a.begin());
        ops_number += pref[r] - pref[l] - (r - l) * x;

        if (m <= x + m / 2LL) {
            r = (lli)(upper_bound(a.begin(), a.end(), (x + m / 2LL) % m) - a.begin());
            ops_number += pref[r] + r * (m - x);

            ops_number += (l - r) * x - (pref[l] - pref[r]);
        } else { // r != n
            ops_number += l * x - pref[l];
            ops_number += (n - r) * (m + x) - (pref[n] - pref[r]);
        }

        ans = min(ans, ops_number);
    }
    
    cout << ans << '\n';
    return;
}
