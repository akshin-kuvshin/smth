// author: Danila "akshin_" Axyonov

#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;
using lli = long long int;

#define plli                pair<lli, lli>
#define mp(_first, _second) make_pair(_first, _second)
#define pb(_elem)           push_back(_elem)

void solve();
lli dfs(lli v, const vector<vector<lli>>& G, const unordered_set<lli>& d, const vector<lli>& w, bool f);

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    solve();
    
    return 0;
}

void solve() {
    lli n;
    cin >> n;
    vector<lli> p(n),
                w(n);
    for (lli& pi : p) {
        cin >> pi;
        --pi;
    }
    for (lli& wi : w)
        cin >> wi;
    lli m;
    cin >> m;
    unordered_set<lli> d;
    while (m--) {
        lli di;
        cin >> di;
        d.insert(--di);
    }

    vector<vector<lli>> G(n);
    for (int i = 1; i < (int)n; ++i)
        G[p[i]].pb((lli)i);
    
    lli ans = dfs(0LL, G, d, w, false);
    cout << ans << '\n';
    return;
}

lli dfs(lli v, const vector<vector<lli>>& G, const unordered_set<lli>& d, const vector<lli>& w, bool f) {
    if (f) { // == true
        lli res = w[v];
        for (lli nb : G[v])
            res += dfs(nb, G, d, w, true);
        return res;
    }
    // now not f

    if (d.contains(v))
        return dfs(v, G, d, w, true);
    // now simple (not in d) vertex
    
    lli res1 = 0LL;
    for (lli nb : G[v])
        res1 += dfs(nb, G, d, w, false);
    lli res2 = dfs(v, G, d, w, true);
    return min(res1, res2);
}
