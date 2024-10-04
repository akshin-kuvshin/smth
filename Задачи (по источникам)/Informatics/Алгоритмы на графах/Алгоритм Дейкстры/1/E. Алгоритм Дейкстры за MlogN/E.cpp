// author: Danila "akshin_" Aksionov

#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;
typedef long long int lli;

#define plli                pair<lli, lli>
#define mp(_first, _second) make_pair(_first, _second)
#define pb(_elem)           push_back(_elem)

#define vertex  first
#define cost    second
#define length  second

const lli MAX_SIZE = (lli)6e4 + 5LL,
          INF = 2009000999LL;

class Compare {
public:
    bool operator ()(const plli &p1, const plli &p2) const {
        if (p1.length == p2.length)
            return p1.vertex < p2.vertex;
        return p1.length < p2.length;
    }
};

lli Q;
lli N;
lli M,
    u,
    v,
    w;
vector<plli> G[MAX_SIZE];
set<plli, Compare> q;
lli d[MAX_SIZE];
bool used[MAX_SIZE];
lli start;

void solve();

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin >> Q;
    while (Q--)
        solve();
    
    return 0;
}

void solve() {
    // Решил со второй попытки, потому что
    // изначально забыл написать очистку G.
    // :(
    for (int i = 0; i < (int)MAX_SIZE; ++i)
        G[i].clear();
    q.clear();
    fill(d, d + MAX_SIZE, INF);
    fill(used, used + MAX_SIZE, false);
    
    cin >> N >> M;
    while (M--) {
        cin >> u >> v >> w;
        G[u].pb(mp(v, w));
        G[v].pb(mp(u, w));
    }
    cin >> start;

    d[start] = 0LL;
    for (int i = 0; i < (int)N; ++i)
        q.insert(mp(i, d[i]));
    
    while (!q.empty()) {
        plli current = *(q.begin());
        q.erase(q.begin());

        if (current.length == INF)
            break;
        
        used[current.vertex] = true;
        for (plli ns : G[current.vertex]) {
            if (used[ns.vertex])
                continue;
            
            lli new_length = current.length + ns.cost;
            if (new_length < d[ns.vertex]) {
                q.erase(mp(ns.vertex, d[ns.vertex]));
                d[ns.vertex] = new_length;
                q.insert(mp(ns.vertex, d[ns.vertex]));
            }
        }
    }
    
    for (int i = 0; i < (int)N; ++i)
        cout << d[i] << ' ';
    cout << '\n';

    return;
}
