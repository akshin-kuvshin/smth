// author: Danila "akshin_" Axyonov

#include <iostream>
#include <vector>
#include <unordered_map>
#include <set>
#include <algorithm>
using namespace std;
typedef long long int lli;

#define plli                pair<lli, lli>
#define mp(_first, _second) make_pair(_first, _second)
#define pb(_elem)           push_back(_elem)




class DSU {
private:
    vector<vector<lli>> l;
    vector<lli> p,
                size;

public:
    DSU(lli n) {
        this->l.resize(n);
        this->p.resize(n);
        this->size.resize(n);
        for (lli u = 0LL; u < n; ++u) {
            this->l[u].pb(u);
            this->p[u] = u;
            this->size[u] = 1LL;
        }
        return;
    }

    lli get(lli a) {
        return this->p[a];
    }

    void unite(lli a, lli b) { // works ~ for O(logn)
        a = this->get(a);
        b = this->get(b);
        if (a == b)
            return;
        if (this->size[a] < this->size[b])
            swap(a, b);
        copy(this->l[b].begin(), this->l[b].end(), back_inserter(this->l[a]));
        for (lli u : this->l[b])
            this->p[u] = a;
        this->size[a] += this->size[b];
        return;
    }

    const vector<lli>& get_comp(lli a) {
        a = this->get(a);
        return this->l[a];
    }
};




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
    vector<unordered_map<char, lli>> tree(n);
    vector<multiset<lli>> G(n);
    for (lli u = 0LL; u < n; ++u) {
        lli l,
            r;
        cin >> l >> r;
        if (l != -1LL) {
            --l;
            G[u].insert(l);
        }
        if (r != -1LL) {
            --r;
            G[u].insert(r);
        }
        tree[u]['l'] = l;
        tree[u]['r'] = r;
    }
    vector<pair<lli, char>> qs(m);
    for (int i = 0; i < (int)m; ++i) {
        lli u,
            hi;
        cin >> u >> hi;
        --u;
        char h = ((hi == 1LL) ? 'l' : 'r');
        G[u].erase(G[u].find(tree[u][h]));
        qs[i] = mp(u, h);
    }

    DSU dsu(n);
    for (lli u = 0LL; u < n; ++u)
        for (lli v : G[u])
            dsu.unite(u, v);
    
    vector<lli> ress(n, -1LL);
    for (lli t = m - 1LL; t >= 0LL; --t) {
        lli u = qs[t].first;
        char h = qs[t].second;
        lli v = tree[u][h];

        if (dsu.get(u) != dsu.get(0LL) and dsu.get(v) != dsu.get(0LL)) {
            if (dsu.get(u) != dsu.get(v))
                dsu.unite(u, v);
        } else if (dsu.get(u) != dsu.get(0LL) or dsu.get(v) != dsu.get(0LL)) {
            if (dsu.get(u) != dsu.get(0LL))
                swap(u, v);
            for (lli ind : dsu.get_comp(v))
                ress[ind] = t;
            dsu.unite(u, v);
        }
    }    
    for (int i = 0; i < (int)n; ++i)
        cout << ress[i] << '\n';
    return;
}
