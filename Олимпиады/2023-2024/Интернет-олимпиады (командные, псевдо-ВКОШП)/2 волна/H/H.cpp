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

#define to                  first
#define cost                second

const lli MAX_SIZE = 250LL + 5LL,
          INF = (lli)1e18;

lli N,
    c[MAX_SIZE];
lli M,
    u,
    v,
    w;
lli answer;
vector<plli> G[MAX_SIZE];
lli d[MAX_SIZE];
bool used[MAX_SIZE];

class Compare {
public:
    bool operator ()(const lli &x, const lli &y) const {
        if (d[x] == d[y])
            return x < y;
        return d[x] < d[y];
    }
};
set<lli, Compare> q;

void solve();
lli dijkstra(lli);

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    solve();
    
    return 0;
}

void solve() {
    cin >> N >> M;
    for (int i = 0; i < (int)N; ++i)
        cin >> c[i];
    while (M--) {
        cin >> u >> v >> w;
        --u, --v;
        G[u].pb(mp(v, w));
        G[v].pb(mp(u, w));
    }

    answer = INF;
    for (lli vertex = 0LL; vertex < N; ++vertex)
        answer = min(answer, dijkstra(vertex));
    cout << answer << '\n';
    return;
}

lli dijkstra(lli start) {
    q.clear();
    fill(d, d + N, INF);
    fill(used, used + N, false);

    d[start] = 0LL;
    for (lli vertex = 0LL; vertex < N; ++vertex)
        q.insert(vertex);
    
    while (!q.empty()) {
        lli current_vertex = *(q.begin());
        lli current_length = d[current_vertex];
        q.erase(q.begin());

        // Этот случай недостижим из-за гарантированной по условию связности графа.
        /* if (current_length == INF)
            break; */
        
        used[current_vertex] = true;
        
        for (plli ns : G[current_vertex]) {
            if (used[ns.to])
                continue;
            
            lli new_length = current_length + ns.cost;
            if (new_length < d[ns.to]) {
                q.erase(ns.to);
                d[ns.to] = new_length;
                q.insert(ns.to);
            }
        }
    }

    lli delivery_price = 0LL;
    for (int i = 0; i < (int)N; ++i)
        delivery_price += c[i] * d[i];
    return delivery_price;
}
