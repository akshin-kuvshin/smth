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
    vector<lli> sz;
    vector<lli> weight;

    lli get(lli a) {
        if (p[a] == a)
            return a;
        return p[a] = get(p[a]);
    }

public:
    void init(lli size) {
        ++size;
        p.resize(size);
        generate(p.begin(), p.end(), []() { static lli i = 0LL; return i++; });
        sz.assign(size, 1LL);
        weight.assign(size, 0LL);
        return;
    }

    void _union(lli a, lli b, lli w) {
        a = get(a);
        b = get(b);
        if (a == b) {
            weight[a] += w;
            return;
        }
        if (sz[a] > sz[b])
            swap(a, b);
        p[a] = b;
        sz[b] += sz[a];
        weight[b] += weight[a] + w;
        return;
    }

    lli get_weight(lli a) {
        a = get(a);
        return weight[a];
    }
};

lli N;
DSU dsu;
lli Q,
    cmd;

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
        if (cmd == 1LL) {
            lli x,
                y,
                w;
            cin >> x >> y >> w;
            dsu._union(x, y, w);
        } else { // cmd == 2LL
            lli x;
            cin >> x;
            cout << dsu.get_weight(x) << '\n';
        }
    }
    
    return;
}
