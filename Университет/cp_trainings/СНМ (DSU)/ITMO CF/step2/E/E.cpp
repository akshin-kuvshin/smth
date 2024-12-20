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
    vector<lli> p,
                size;
    
    lli __get(lli a) {
        if (this->p[a] != a)
            this->p[a] = this->__get(this->p[a]);
        return this->p[a];
    }

public:
    DSU(lli n) {
        this->p.resize(n + 1LL);
        generate(this->p.begin(), this->p.end(), []() { static lli i = 0LL; return i++; });
        this->size.assign(n + 1LL, 1LL);
        return;
    }

    void unite(lli a, lli b) {
        a = this->__get(a);
        b = this->__get(b);
        if (a == b)
            return;
        if (this->size[a] < this->size[b])
            swap(a, b);
        this->p[b] = a;
        this->size[a] += this->size[b];
        return;
    }

    bool eq(lli a, lli b) {
        return this->__get(a) == this->__get(b);
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
    vector<tuple<lli, lli, lli>> ribs(m);
    for (int i = 0; i < (int)m; ++i)
        cin >> get<1>(ribs[i]) >> get<2>(ribs[i]) >> get<0>(ribs[i]);
    sort(ribs.begin(), ribs.end());

    DSU dsu(n);
    lli ans = 0LL,
        cnt = 0LL;
    for (auto [d, u, v] : ribs) {
        if (cnt == n - 1LL)
            break;
        if (dsu.eq(u, v))
            continue;
        dsu.unite(u, v);
        ans += d;
        ++cnt;
    }
    cout << ans << '\n';
    return;
}
