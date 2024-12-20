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
    lli __n;
    vector<lli> p;
    
    // works ~ for O(logn)
    lli __get(lli a) {
        if (this->p[a] != a)
            this->p[a] = this->__get(this->p[a]);
        return this->p[a];
    }

public:
    DSU(lli n) {
        this->__n = n;
        this->p.resize(this->__n + 2LL);
        generate(p.begin(), p.end(), []() { static lli i = 0LL; return i++; });
        return;
    }

    void kill(lli a) {
        this->p[a] = a + 1LL;
        return;
    }

    lli get_right(lli a) {
        lli right = this->__get(a);
        return (right <= this->__n ? right : -1LL);
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
