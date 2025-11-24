// author: Danila "akshin_" Axyonov

#include <iostream>
#include <vector>
#include <set>
using namespace std;
using lli = long long int;

#define plli                pair<lli, lli>
#define mp(_first, _second) make_pair(_first, _second)
#define pb(_elem)           push_back(_elem)

const lli INF = (lli)1e18 + 1LL;

void solve();
vector<lli> dijkstra(lli n, const vector<vector<lli>>& G, lli base);

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    solve();
    
    return 0;
}

void solve() {
    lli n;
    cin >> n;
    vector<vector<lli>> G(n);
    lli m,
        base;
    cin >> m >> base;
    --base;
    while (m--) {
        lli u,
            v;
        cin >> u >> v;
        --u; --v;
        G[u].pb(v);
        G[v].pb(u);
    }

    auto d_base = dijkstra(n, G, base);

    lli n_max = 0LL;
    for (int i = 0; i < (int)n; ++i) {
        if (i == (int)base)
            continue;

        auto d = dijkstra(n, G, (lli)i);

        lli ni = 0LL;
        for (int j = 0; j < (int)n; ++j) {
            if (j == i)
                continue;
            ni += (lli)(d[j] < d_base[j]);
        }
        n_max = max(n_max, ni);
    }
    
    cout << n_max << '\n';
}

vector<lli> dijkstra(lli n, const vector<vector<lli>>& G, lli base) {
    vector<lli> d(n, INF);
    set<plli> S;

    d[base] = 0LL;
    S.insert(mp(0LL, base));
    while (not S.empty()) {
        auto [cur_d, cur_v] = *S.begin();
        S.erase(S.begin());

        for (lli ns : G[cur_v])
            if (cur_d + 1LL < d[ns]) {
                S.erase(mp(d[ns], ns));
                d[ns] = cur_d + 1LL;
                S.insert(mp(d[ns], ns));
            }
    }

    return d;
}
