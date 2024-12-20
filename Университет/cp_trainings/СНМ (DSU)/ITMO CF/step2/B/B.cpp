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
    lli n;
    vector<lli> p;

public:
    DSU(lli __n) {
        this->n = __n;
        this->p.resize(this->n + 1LL);
        generate(this->p.begin(), this->p.end(), []() { static lli i = 0LL; return i++; });
        return;
    }

    lli get(lli a) {
        if (this->p[a] != a)
            this->p[a] = this->get(this->p[a]);
        return this->p[a];
    }

    void kill(lli a) {
        if (a == this->n) {
            this->p[this->n] = 1LL;
            return;
        }
        this->p[a] = a + 1LL;
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
    lli n;
    cin >> n;
    vector<lli> drivers(n);
    for (int i = 0; i < (int)n; ++i)
        cin >> drivers[i];
    
    DSU dsu(n);
    for (lli wanted_place : drivers) {
        lli real_place = dsu.get(wanted_place);
        cout << real_place << ' ';
        dsu.kill(real_place);
    }
    cout << '\n';
    return;
}
