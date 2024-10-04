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
    vector<lli> sz;

public:
    void init(lli size) {
        p.resize(size + 1LL);
        generate(p.begin(), p.end(), []() { static lli i = 0LL; return i++; });
        sz.assign(size + 1LL, 1LL);
        return;
    }

    lli get(lli a) {
        return (a == p[a] ? a : p[a] = get(p[a]));
    }

    void _union(lli a, lli b) {
        a = get(a);
        b = get(b);
        if (a == b)
            return;
        if (sz[a] > sz[b])
            swap(a, b);
        p[a] = p[b];
        sz[b] += sz[a];
        return;
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
            lli u,
                v;
            cin >> u >> v;
            cout << (dsu.get(u) == dsu.get(v) ? "YES" : "NO") << '\n';
        }
    }
    
    return;
}
