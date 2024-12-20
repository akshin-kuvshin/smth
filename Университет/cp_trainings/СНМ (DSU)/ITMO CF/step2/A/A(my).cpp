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
    const lli __INF = 1000000000LL; // 10^9
    vector<lli> p,
                size,
                right;
    
    lli __get(lli a) {
        if (this->p[a] != a)
            this->p[a] = this->__get(this->p[a]);
        return this->p[a];
    }

    void __unite(lli a, lli b) {
        a = this->__get(a);
        b = this->__get(b);
        if (a == b)
            return;
        if (this->size[a] < this->size[b])
            swap(a, b);
        this->p[b] = a;
        this->size[a] += this->size[b];
        this->right[a] = max(this->right[a], this->right[b]);
        return;
    }

public:
    DSU(lli n) {
        n += 2LL;
        this->p.resize(n);
        generate(p.begin(), p.end(), []() { static lli i = 0LL; return i++; });
        this->size.assign(n, 1LL);
        this->right = this->p;
        this->right.back() = this->__INF;
        return;
    }

    void kill(lli a) {
        this->__unite(a, a + 1LL);
        return;
    }

    lli get_right(lli a) {
        a = this->__get(a);
        return (this->right[a] < this->__INF ? this->right[a] : -1LL);
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
        char cmd;
        lli a;
        cin >> cmd >> a;
        if (cmd == '-')
            dsu.kill(a);
        else // cmd == '?'
            cout << dsu.get_right(a) << '\n';
    }
    
    return;
}
