// author: Danila "akshin_" Axyonov

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int INF = (int)2e9 + 29;



class DSU {
private:
    vector<int> p;
    vector<int> r;
    int size;

public:
    void init(int orsize) {
        this->size = orsize;
        this->p.resize(this->size);
        this->r.resize(this->size);
        this->clear();
        return;
    }

    void clear() {
        for (int i = 0; i < size; ++i) {
            this->p[i] = i;
            this->r[i] = 0;
        }
        return;
    }

    int get(int a) {
        if (this->p[a] != a)
            this->p[a] = this->get(this->p[a]);
        return this->p[a];
    }

    void unite(int a, int b) {
        a = this->get(a);
        b = this->get(b);
        if (a == b)
            return;
        if (this->r[a] == this->r[b])
            ++this->r[a];
        if (this->r[a] > this->r[b])
            this->p[b] = a;
        else // this->r[a] < this->r[b]
            this->p[a] = b;
        return;
    }
};



struct Rib {
    int u;
    int v;
    int w;
};



void solve();

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    solve();
    
    return 0;
}

void solve() {
    int n,
        m;
    cin >> n >> m;
    vector<Rib> ribs(m);
    for (int i = 0; i < m; ++i) {
        cin >> ribs[i].u; --ribs[i].u;
        cin >> ribs[i].v; --ribs[i].v;
        cin >> ribs[i].w;
    }
    sort(ribs.begin(), ribs.end(), [](Rib r1, Rib r2) { return r1.w < r2.w; });

    DSU dsu;
    dsu.init(n);
    int min_d = INF;
    for (int i = 0; i < m; ++i) {
        dsu.clear();
        int _min = INF,
            _max = -INF,
            cnt = 0;
        for (int j = i; j < m and cnt < n - 1; ++j) {
            if (dsu.get(ribs[j].u) == dsu.get(ribs[j].v))
                continue;
            dsu.unite(ribs[j].u, ribs[j].v);
            _min = min(_min, ribs[j].w);
            _max = max(_max, ribs[j].w);
            ++cnt;
        }
        if (cnt == n - 1)
            min_d = min(min_d, _max - _min);
    }
    
    if (min_d == INF) // there is no MST (minimal spanning tree)
        cout << "NO\n";
    else // there is at least one MST
        cout << "YES\n" << min_d << '\n';

    return;
}
