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




class DSU {
private:
    vector<lli> p,
                size;

public:
    DSU(lli n) {
        this->p.resize(n);
        generate(this->p.begin(), this->p.end(), []() { static lli i = 0LL; return i++; });
        this->size.assign(n, 1LL);
        return;
    }

    lli get(lli a) {
        if (this->p[a] != a)
            this->p[a] = this->get(this->p[a]);
        return this->p[a];
    }

    void union_(lli a, lli b) {
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
        lli u, v;
        cin >> cmd >> u >> v;
        --u, --v;
        if (cmd == "union")
            dsu.union_(u, v);
        else // cmd == "get"
            cout << (dsu.get(u) == dsu.get(v) ? "YES" : "NO") << '\n';
    }
    return;
}
