// author: Danila "akshin_" Axyonov

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;
typedef long long int lli;

#define plli                pair<lli, lli>
#define mp(_first, _second) make_pair(_first, _second)
#define pb(_elem)           push_back(_elem)

class DSU {
private:
    vector<lli> p;
    vector<lli> _min;
    vector<lli> _max;
    vector<lli> sz;

    lli get(lli a) {
        return (a == p[a] ? a : p[a] = get(p[a]));
    }

public:
    void init(lli size) {
        p.resize(size + 1LL);
        sz.resize(size + 1LL);
        _min.resize(size + 1LL);
        _max.resize(size + 1LL);
        for (lli i = 1LL; i < size + 1LL; ++i)
            p[i] = _min[i] = _max[i] = i;
        fill(++sz.begin(), sz.end(), 1LL);
        return;
    }

    void _union(lli a, lli b) {
        a = get(a);
        b = get(b);
        if (a == b)
            return;
        if (sz[a] > sz[b])
            swap(a, b);
        p[a] = p[b];
        _min[b] = min(_min[b], _min[a]);
        _max[b] = max(_max[b], _max[a]);
        sz[b] += sz[a];
        return;
    }

    void get_and_print(lli a) {
        a = get(p[a]);
        cout << _min[a] << ' ' << _max[a] << ' ' << sz[a] << '\n';
    }
};

lli N;
DSU dsu;
lli Q;
string cmd;

void solve();

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    solve();
    
    return 0;
}

void solve() {
    cin >> N;
    dsu.init(N);

    cin >> Q;
    while (Q--) {
        cin >> cmd;
        if (cmd == "union") {
            lli u,
                v;
            cin >> u >> v;
            dsu._union(u, v);
        } else { // cmd == "get"
            lli u;
            cin >> u;
            dsu.get_and_print(u);
        }
    }
    
    return;
}
