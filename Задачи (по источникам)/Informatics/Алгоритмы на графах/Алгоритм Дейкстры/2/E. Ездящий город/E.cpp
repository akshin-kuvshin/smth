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

#define NON_DEF             -1LL

const lli GRAPH_MAX_SIZE = (lli)1e4 + 5LL,
          WAY_MAX_SIZE = (lli)5e1 + 5LL,
          INF = (lli)1e18;

class Rib {
public:
    lli to;
    lli start;
    lli duration;

    Rib() {
        to = start = duration = NON_DEF;
        return;
    }

    Rib(lli new_to, lli new_start, lli new_duration) {
        to = new_to;
        start = new_start;
        duration = new_duration;
        return;
    }
};

lli N;
lli K,
    __from,
    __to,
    __start,
    __duration;
lli M,
    P[WAY_MAX_SIZE];
lli current_time; // answer
vector<Rib> G[GRAPH_MAX_SIZE];
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
lli get_arrival_time(lli, lli, lli);

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    input();
    solve();
    
    return 0;
}

void input() {
    cin >> N >> K;
    while (K--) {
        cin >> __from >> __to >> __start >> __duration;
        --__from, --__to;
        G[__from].pb(Rib(__to, __start, __duration));
    }
    cin >> M;
    for (int i = 0; i < (int)M; ++i) {
        cin >> P[i];
        --P[i];
    }

    return;
}

void solve() {
    for (int i = 0; i + 1 < (int)M; ++i)
        current_time = get_arrival_time(P[i], P[i + 1], current_time);
    cout << ((current_time != INF) ? current_time : NON_DEF) << '\n';
    return;
}

lli get_arrival_time(lli s, lli f, lli s_time) {
    q.clear();
    fill(d, d + N, INF);
    fill(used, used + N, false);

    d[s] = s_time;
    for (lli vertex = 0LL; vertex < N; ++vertex)
        q.insert(vertex);
    
    while (!q.empty()) {
        lli current_vertex = *(q.begin());
        lli current_length = d[current_vertex];
        q.erase(q.begin());
        
        if (current_length == INF)
            break;
        
        used[current_vertex] = true;
        if (current_vertex == f)
            break;
        
        for (Rib ns : G[current_vertex]) {
            if (used[ns.to])
                continue;
            
            lli new_length = ((current_length % ns.start) ? (current_length - current_length % ns.start + ns.start) : current_length) + ns.duration;
            if (new_length < d[ns.to]) {
                q.erase(ns.to);
                d[ns.to] = new_length;
                q.insert(ns.to);
            }
        }
    }

    return d[f];
}
