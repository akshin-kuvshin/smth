// author: Danila "akshin_" Axyonov

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long int lli;

#define plli                pair<lli, lli>
#define mp(_first, _second) make_pair(_first, _second)
#define pb(_elem)           push_back(_elem)




class DSU {
private:
    vector<lli> p;
    vector<lli> size;

public:
    DSU(lli original_size) {
        this->p.resize(original_size);
        this->size.resize(original_size);
        for (lli i = 0LL; i < original_size; ++i) {
            this->p[i] = i;
            this->size[i] = 1LL;
        }
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
        if (this->size[a] < this->size[b])
            swap(a, b);
        this->p[b] = a;
        this->size[a] += this->size[b];
        return;
    }
};




struct Rib {
    lli u;
    lli v;
    lli cost;
    lli ind;
    bool used;
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
        m,
        s;
    cin >> n >> m >> s;
    vector<Rib> ribs(m);
    lli full_sum = 0LL;
    for (lli i = 0LL; i < m; ++i) {
        cin >> ribs[i].u; --ribs[i].u;
        cin >> ribs[i].v; --ribs[i].v;
        cin >> ribs[i].cost;
        full_sum += ribs[i].cost;
        ribs[i].ind = i + 1LL;
        ribs[i].used = false;
    }
    sort(ribs.begin(), ribs.end(), [](Rib r1, Rib r2) {
        return r1.cost > r2.cost; // if ">=" is written instead of ">", then runtime error occurs.
    });

    DSU dsu(n);
    lli cur_sum = 0LL,
        cnt = 0LL;
    for (int i = 0; i < (int)m and cnt < n - 1LL; ++i) {
        if (dsu.get(ribs[i].u) == dsu.get(ribs[i].v))
            continue;
        dsu.unite(ribs[i].u, ribs[i].v);
        cur_sum += ribs[i].cost;
        ribs[i].used = true;
        ++cnt;
    }

    for (int i = 0; i < (int)m and cur_sum < full_sum - s; ++i) {
        if (ribs[i].used) continue;
        cur_sum += ribs[i].cost;
        ribs[i].used = true;
        ++cnt;
    }

    sort(ribs.begin(), ribs.end(), [](Rib r1, Rib r2) {
        return r1.ind < r2.ind;
    });
    lli k = m - cnt;
    cout << k << '\n';
    for (int i = 0; i < (int)m; ++i)
        if (not ribs[i].used)
            cout << ribs[i].ind << ' ';
    cout << '\n';
    
    return;
}
