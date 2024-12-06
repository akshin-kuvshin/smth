// author: Danila "akshin_" Axyonov

#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;
typedef long long int lli;

#define plli                pair<lli, lli>
#define mp(_first, _second) make_pair(_first, _second)
#define pb(_elem)           push_back(_elem)




class DSU {
private:
    vector<lli> p,
                min_,
                max_,
                size;

public:
    DSU(lli n) {
        this->p.resize(n);
        generate(this->p.begin(), this->p.end(), []() { static lli i = 0LL; return i++; });
        this->min_ = p;
        this->max_ = p;
        this->size.assign(n, 1LL);
        return;
    }

    lli get(lli a) {
        if (this->p[a] != a)
            this->p[a] = this->get(this->p[a]);
        return this->p[a];
    }

    unordered_map<string, lli> min_max_size(lli a) {
        a = this->get(a);
        unordered_map<string, lli> res;
        res["min"] = this->min_[a];
        res["max"] = this->max_[a];
        res["size"] = this->size[a];
        return res;
    }

    void union_(lli a, lli b) {
        a = this->get(a);
        b = this->get(b);
        if (a == b)
            return;
        if (this->size[a] < this->size[b])
            swap(a, b);
        this->p[b] = a;
        this->min_[a] = min(this->min_[a], this->min_[b]);
        this->max_[a] = max(this->max_[a], this->max_[b]);
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
        cin >> cmd;
        if (cmd == "union") {
            lli u, v;
            cin >> u >> v;
            dsu.union_(--u, --v);
        } else { // cmd == "get"
            lli a;
            cin >> a;
            auto res = dsu.min_max_size(--a);
            cout << (res["min"] + 1LL) << ' ' << (res["max"] + 1LL) << ' ' << res["size"] << '\n';
        }
    }
    return;
}
