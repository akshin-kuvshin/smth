// author: Danila "akshin_" Axyonov

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long int lli;

#define plli                pair<lli, lli>
#define mp(_first, _second) make_pair(_first, _second)
#define pb(_elem)           push_back(_elem)

#define ind                 first
#define exp                 second




class DSU {
private:
    vector<lli> p,
                size,
                e;

    plli get(lli a) {
        if (a == this->p[a])
            return mp(a, 0LL);
        plli res = this->get(this->p[a]);
        this->p[a] = res.ind;
        this->e[a] += res.exp;
        return mp(this->p[a], this->e[a]);
    }

public:
    DSU(lli n) {
        p.resize(n + 1LL);
        generate(p.begin(), p.end(), []() { static lli i = 0LL; return i++; });
        size.assign(n + 1LL, 1LL);
        e.assign(n + 1LL, 0LL);
        return;
    }

    void unite(lli a, lli b) {
        a = this->get(a).ind;
        b = this->get(b).ind;
        if (a == b)
            return;
        if (this->size[a] < this->size[b])
            swap(a, b);
        this->p[b] = a;
        this->size[a] += this->size[b];
        this->e[b] -= this->e[a];
        return;
    }

    void add_exp(lli a, lli val) {
        a = this->get(a).ind;
        this->e[a] += val;
        return;
    }

    lli get_exp(lli a) {
        lli prim = this->get(a).ind;
        if (a == prim)
            return this->e[a];
        return this->e[a] + this->e[prim];
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
        q;
    cin >> n >> q;
    DSU dsu(n);
    while (q--) {
        string cmd;
        cin >> cmd;
        if (cmd == "join") {
            lli x,
                y;
            cin >> x >> y;
            dsu.unite(x, y);
        } else if (cmd == "add") {
            lli x,
                v;
            cin >> x >> v;
            dsu.add_exp(x, v);
        } else { // cmd == "get"
            lli x;
            cin >> x;
            cout << dsu.get_exp(x) << '\n';
        }
    }    
    return;
}
