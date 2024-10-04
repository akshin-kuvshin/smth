// author: Danila "akshin_" Axyonov

#include <iostream>
#include <vector>
#include <queue>
using namespace std;
typedef long long int lli;

#define plli                pair<lli, lli>
#define mp(_first, _second) make_pair(_first, _second)
#define pb(_elem)           push_back(_elem)

const lli MAX_SIZE = (lli)2e4 + 5LL;

class Rib {
public:
    lli to;
    lli cost;

    Rib() {
        this->to = 0LL;
        this->cost = 0LL;
        return;
    }

    Rib(lli _to, lli _cost) {
        this->to = _to;
        this->cost = _cost;
        return;
    }

    bool operator < (const Rib &r) const {
        return this->cost > r.cost;
    }
};

lli N;
vector<Rib> G[MAX_SIZE];
lli M,
    u,
    v,
    w;

priority_queue<Rib> q;
bool used[MAX_SIZE];
lli cnt;
lli ans;

void solve();

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    solve();
    
    return 0;
}

void solve() {
    cin >> N >> M;
    while (M--) {
        cin >> u >> v >> w;
        G[u].pb(Rib(v, w));
        G[v].pb(Rib(u, w));
    }

    q.push(Rib(1LL, 0LL));
    while (cnt < N) {
        Rib cur = q.top();
        q.pop();

        if (used[cur.to])
            continue;
        
        used[cur.to] = true;
        ++cnt;
        ans += cur.cost;
        for (Rib ns : G[cur.to]) {
            if (used[ns.to])
                continue;
            q.push(ns);
        }
    }
    
    cout << ans << '\n';
    return;
}
