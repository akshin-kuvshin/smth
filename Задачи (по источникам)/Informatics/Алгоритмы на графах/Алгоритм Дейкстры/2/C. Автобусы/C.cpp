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

#define NO_WAY              -1LL

const lli MAX_SIZE = (lli)1e2 + 5LL,
          INF = (lli)1e6;

class Rib {
public:
    lli to;
    lli t_start;
    lli t_finish;

    Rib() {
        to = t_start = t_finish = 0LL;
        return;
    }

    Rib(lli __to, lli __t_start, lli __t_finish) {
        to = __to;
        t_start = __t_start;
        t_finish = __t_finish;
        return;
    }
};

lli N,
    start,
    finish;
lli M,
    _from,
    _t_start,
    _to,
    _t_finish;
vector<Rib> G[MAX_SIZE];
lli d[MAX_SIZE];
bool used[MAX_SIZE];

// Пишу компаратор и сам set после объявления всего остального,
// потому что массив d[] должен быть объявлен до компаратора,
// т.к. упомянается в нём.
class Compare {
public:
    bool operator ()(const lli &u, const lli &v) const {
        if (d[u] == d[v])
            return u < v;
        return d[u] < d[v];
    }
};
set<lli, Compare> q;

void solve();

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    solve();
    
    return 0;
}

void solve() {
    cin >> N >> start >> finish;
    cin >> M;
    while (M--) {
        cin >> _from >> _t_start >> _to >> _t_finish;
        G[_from].pb(Rib(_to, _t_start, _t_finish));
    }

    fill(d + 1LL, d + 1LL + N, INF);
    d[start] = 0LL;
    for (lli u = 1LL; u <= N; ++u)
        q.insert(u);
    
    while (!q.empty()) {
        lli cur_v = *(q.begin());
        q.erase(q.begin());
        lli cur_d = d[cur_v];

        if (cur_d == INF)
            break;
        
        used[cur_v] = true;
        if (cur_v == finish)
            break;
        
        for (Rib ns : G[cur_v]) {
            if (used[ns.to])
                continue;
            
            if (cur_d > ns.t_start)
                continue;
            if (ns.t_finish < d[ns.to]) {
                q.erase(ns.to);
                d[ns.to] = ns.t_finish;
                q.insert(ns.to);
            }
        }
    }
    
    cout << (used[finish] ? d[finish] : NO_WAY) << '\n';
    return;
}
