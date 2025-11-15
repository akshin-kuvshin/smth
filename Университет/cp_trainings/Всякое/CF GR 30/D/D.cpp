// author: Danila "akshin_" Axyonov

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std;

#define pb(elem_)   push_back(elem_)

const int INF = (int)1e9 + 1;

void solve();

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int Q;
    cin >> Q;
    while (Q--)
        solve();
    
    return 0;
}

void solve() {
    int n,
        k_max;
    cin >> n >> k_max;
    string s,
           t;
    cin >> s >> t;
    
    unordered_map<char, vector<int>> m;
    for (int i = 0; i < n; ++i)
        m[s[i]].pb(i);
    vector<int> p(n);
    p.pb(INF);
    for (int i = n - 1; i >= 0; --i) {
        auto it = --upper_bound(m[t[i]].begin(), m[t[i]].end(), p[i + 1]);
        if (it + 1 == m[t[i]].begin()) {
            cout << "-1\n";
            return;
        }
        p[i] = *it;

        m[s[i]].pop_back();
    }

    int k = 0;
    for (int i = 0; i < n; ++i)
        k = max(k, i - p[i]);
    if (k > k_max) {
        cout << "-1\n";
        return;
    }
    cout << k << '\n';

    vector<int> q(n);
    for (int i = 0; i < n; ++i)
        q[i] = i;
    while (k--) {
        for (int i = n - 1; i > 0; --i)
            q[i] = ((q[i] == p[i]) ? q[i] : q[i - 1]);
        for (int i = 0; i < n; ++i)
            cout << s[q[i]];
        cout << '\n';
    }
}
