// author: Danila "akshin_" Axyonov

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long int lli;

#define plli                pair<lli, lli>
#define mp(_first, _second) make_pair(_first, _second)
#define pb(_elem)           push_back(_elem)

const lli MAX_SIZE = (lli)1e5 + 5LL;

class DSU {
private:
    vector<lli> p;
    vector<lli> sz;

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
        return;
    }

    bool _union(lli a, lli b) {
        a = get(a);
        b = get(b);
        if (a == b)
            return false;
        if (sz[a] > sz[b])
            swap(a, b);
        p[a] = b;
        sz[b] += sz[a];
        return true;
    }
};

class Rib {
public:
    lli b;
    lli e;
    lli w;
};

lli N;
DSU dsu;
lli M;
Rib rib[MAX_SIZE];
lli cnt,
    ans;

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
    cin >> M;
    for (int i = 0; i < (int)M; ++i)
        cin >> rib[i].b >> rib[i].e >> rib[i].w;
    sort(rib, rib + M, [](const Rib &r1, const Rib &r2) {
        return r1.w < r2.w;
    });
    
    for (int i = 0; i < (int)M and cnt < N - 1LL; ++i)
        if (dsu._union(rib[i].b, rib[i].e)) {
            ++cnt;
            ans += rib[i].w;
        }

    cout << ans << '\n';
    return;
}
