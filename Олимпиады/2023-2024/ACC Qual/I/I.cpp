// author: Danila "akshin_" Axyonov

#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
using namespace std;
typedef long long int lli;

#define plli                pair<lli, lli>
#define mp(_first, _second) make_pair(_first, _second)
#define pb(_elem)           push_back(_elem)

const lli MAX_SIZE = (lli)1e5 + 5LL,
          INF = (lli)1e18 + 1LL;

class Rib {
public:
    lli to;
    lli t;
    lli w;

    Rib(lli _to, lli _t, lli _w) {
        to = _to;
        t = _t;
        w = _w;
        return;
    }
};

lli N,
    M;
vector<Rib> G[MAX_SIZE];
lli d[MAX_SIZE];

class Compare {
public:
    bool operator ()(lli u, lli v) const {
        return d[u] <= d[v];
    }
};
set<lli, Compare> Q;

void solve();

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    fill(d, d + MAX_SIZE, INF);
    solve();
    
    return 0;
}

void solve() {
    cin >> N >> M;
    while (M--) {
        lli a,
            b,
            t,
            w;
        cin >> a >> b >> t >> w;
        G[a].pb(Rib(b, t, w));
    }

    d[1] = 0LL;
    Q.insert(1LL);
    while (!Q.empty()) {
        lli cur = *Q.begin();
        Q.erase(Q.begin());

        for (Rib r : G[cur]) {
            lli to = r.to;
            lli new_d = d[cur];
            if (new_d % r.t == 0LL)
                new_d += r.w;
            else // new_d % r.t != 0LL
                new_d = new_d - new_d % r.t + r.t + r.w;
            
            if (d[to] > new_d) {
                Q.erase(to);
                d[to] = new_d;
                Q.insert(to);
            }
        }
    }
    
    cout << d[N] << '\n';
    return;
}
