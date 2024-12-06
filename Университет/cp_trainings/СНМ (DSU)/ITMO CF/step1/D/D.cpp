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
        this->p.resize(n + 1LL);
        generate(this->p.begin(), this->p.end(), []() { static lli i = 0LL; return i++; });
        this->size.assign(n + 1LL, 1LL);
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
        k;
    cin >> n >> m >> k;
    {   lli tmp;
        while (m--)
            cin >> tmp >> tmp;
    }
    vector<tuple<string, lli, lli>> qs(k);
    for (int i = 0; i < (int)k; ++i)
        cin >> get<0>(qs[i]) >> get<1>(qs[i]) >> get<2>(qs[i]);
    
    reverse(qs.begin(), qs.end());
    vector<string> ress;
    DSU dsu(n);
    for (int i = 0; i < (int)k; ++i) {
        lli u = get<1>(qs[i]),
            v = get<2>(qs[i]);
        if (get<0>(qs[i]) == "ask")
            ress.pb((dsu.get(u) == dsu.get(v)) ? "YES\n" : "NO\n");
        else // get<0>(qs[i]) == "cut"
            dsu.unite(u, v);
    }
    reverse(ress.begin(), ress.end());
    for (string res : ress)
        cout << res;
    return;
}
