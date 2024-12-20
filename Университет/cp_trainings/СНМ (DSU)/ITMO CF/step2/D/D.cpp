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
    vector<lli> d;

    plli __get(lli a) {
        if (this->p[a] == a)
            return mp(a, 0LL);
        auto [par, depth] = this->__get(this->p[a]);
        this->p[a] = par;
        this->d[a] += depth;
        return mp(this->p[a], this->d[a]);
    }

public:
    DSU(lli n) {
        this->p.resize(n + 1LL);
        generate(this->p.begin(), this->p.end(), []() { static lli i = 0LL; return i++; });
        this->d.assign(n + 1LL, 0LL);
        return;
    }

    void unite(lli a, lli b) {
        this->p[a] = b;
        ++this->d[a];
        return;
    }

    lli get_d(lli a) {
        return this->__get(a).second;
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

    DSU dsu(n);
    while (m--) {
        lli cmd;
        cin >> cmd;
        if (cmd == 1LL) {
            lli a,
                b;
            cin >> a >> b;
            dsu.unite(a, b);
        } else { // cmd == 2LL
            lli c;
            cin >> c;
            cout << dsu.get_d(c) << '\n';
        }
    }
    
    return;
}
