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

const lli GRAPH_MAX_SIZE = (lli)1e6 + 5LL,
          LIFT_MAX_SIZE = (lli)1e3 + 5LL,
          INF = (lli)1e18;

lli N,
    go_up_cost,     // U
    go_down_cost,   // D
    come_in_cost,   // I
    come_out_cost;  // J
lli L,
    K,
    lift[LIFT_MAX_SIZE];
lli start,
    finish;
vector<plli> G[GRAPH_MAX_SIZE];
lli d[GRAPH_MAX_SIZE];
bool used[GRAPH_MAX_SIZE];

class Compare {
public:
    bool operator ()(const lli &u, const lli &v) const {
        if (d[u] == d[v])
            return u < v;
        return d[u] < d[v];
    }
};
set<lli, Compare> q;

void input();
void solve();

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    input();
    solve();
    
    return 0;
}

void input() {
    cin >> N;

    cin >> go_up_cost >> go_down_cost;
    for (int i = 0; i < (int)N; ++i) {
        if (0 <= i - 1)
            G[i].pb(mp((lli)(i - 1), go_down_cost));
        if (i + 1 < N)
            G[i].pb(mp((lli)(i + 1), go_up_cost));
    }

    cin >> come_in_cost >> come_out_cost >> L;
    while (L--) {
        cin >> K;
        for (int i = 0; i < (int)K; ++i) {
            cin >> lift[i];
            --lift[i];
        }

        for (int i = 0; i < (int)K; ++i)
            for (int j = i + 1; j < (int)K; ++j) {
                G[lift[i]].pb(mp(lift[j], come_in_cost + come_out_cost));
                G[lift[j]].pb(mp(lift[i], come_in_cost + come_out_cost));
            }
    }

    return;
}

void solve() {
    q.clear();
    fill(d, d + N, INF);
    fill(used, used + N, false);

    start = 0LL;
    finish = N - 1LL;

    d[start] = 0LL;
    for (lli _v = 0LL; _v < N; ++_v)
        q.insert(_v);
    
    while (!q.empty()) {
        lli current_vertex = *(q.begin());
        lli current_length = d[current_vertex];
        q.erase(q.begin());

        // Такой случай невозможен, поэтому я закомментировал его.
        /* if (current_length == INF)
            break; */
        
        used[current_vertex] = true;
        if (current_vertex == finish)
            break;
        
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
    
    cout << d[finish] << '\n';
    return;
}
