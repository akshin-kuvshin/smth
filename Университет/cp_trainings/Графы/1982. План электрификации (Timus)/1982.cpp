// author: Danila "akshin_" Axyonov

#include <iostream>
#include <vector>
#include <unordered_set>
#include <algorithm>
using namespace std;
typedef long long int lli;

#define plli                pair<lli, lli>
#define mp(_first, _second) make_pair(_first, _second)
#define pb(_elem)           push_back(_elem)

const lli INF = (lli)1e18 + 1LL;



class DSU {
private:
    vector<lli> p;
    vector<lli> r;

public:
    DSU(lli n, const unordered_set<lli> &el) {
        this->p.resize(n);
        generate(this->p.begin(), this->p.end(), []() { static lli i = 0LL; return i++; });
        this->r.assign(n, 0LL);
        for (auto v : el)
            this->r[v] = INF;
        return;
    }

    lli get(lli a) {
        if (this->p[a] != a)
            this->p[a] = this->get(this->p[a]);
        return this->p[a];
    }

    void unite(lli a, lli b) {
        a = this->get(a);
        b = this->get(b);
        if (a == b)
            return;
        if (this->r[a] == this->r[b])
            ++this->r[a];
        if (this->r[a] > this->r[b])
            this->p[b] = a;
        else
            this->p[a] = b;
        return;
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
        k;
    cin >> n >> k;
    unordered_set<lli> el;
    for (int _ = 0; _ < (int)k; ++_) {
        lli v;
        cin >> v;
        el.insert(--v);
    }
    vector<pair<lli, plli>> ribs;
    for (int i = 0; i < (int)n; ++i)
        for (int j = 0; j < (int)n; ++j) {
            lli cost;
            cin >> cost;
            if (i < j)
                ribs.pb(mp(cost, mp((lli)i, (lli)j)));
        }
    sort(ribs.begin(), ribs.end());

    DSU dsu(n, el);
    lli ans = 0LL,
        cnt = 0LL;
    for (auto [cost, p] : ribs) {
        if (cnt == n - k)
            break;
        
        lli u = dsu.get(p.first),
            v = dsu.get(p.second);
        if (u != v and not (el.contains(u) and el.contains(v))) {
            dsu.unite(u, v);
            ans += cost;
            ++cnt;
        }
    }
    
    cout << ans << '\n';
    return;
}
