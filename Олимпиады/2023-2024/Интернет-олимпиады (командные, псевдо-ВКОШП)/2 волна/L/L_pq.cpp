// author: Danila "akshin_" Aksionov

#include <iostream>
#include <vector>
#include <queue>
using namespace std;
typedef long long int lli;
 
#define plli                                pair<lli, lli>
#define mp(_first, _second)                 make_pair(_first, _second)
#define pb(elem)                            push_back(elem)
 
#define to                                  first
#define cost                                second
 
const lli MAX_SIZE = (lli)2e5 + 5LL;
 
class Compare {
public:
    bool operator ()(const plli &r1, const plli &r2) const {
        return r1.cost > r2.cost;
    }
};
 
lli N,
    p[MAX_SIZE];
lli M,
    u,
    v,
    d,
    w;
vector<plli> G[MAX_SIZE];
priority_queue<plli, vector<plli>, Compare> q;
bool used[MAX_SIZE];
lli cnt,
    summary_weight; // answer
 
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
    cin >> N >> M;
    for (int i = 0; i < (int)N; ++i)
        cin >> p[i];
    while (M--) {
        cin >> u >> v >> d;
        --u, --v;
        w = (p[u] ^ d) + (p[v] ^ d);
        G[u].pb(mp(v, w));
        G[v].pb(mp(u, w));
    }
    return;
}
 
void solve() {
    used[0] = true;
    for (plli ns : G[0])
        q.push(ns);
     
    while (cnt < N - 1LL) {
        plli current = q.top();
        q.pop();
         
        if (used[current.to])
            continue;
        used[current.to] = true;
         
        ++cnt;
        summary_weight += current.cost;
         
        for (plli ns : G[current.to]) {
            if (used[ns.to])
                continue;
            q.push(ns);
        }
    }
     
    cout << summary_weight << '\n';
    return;
}
