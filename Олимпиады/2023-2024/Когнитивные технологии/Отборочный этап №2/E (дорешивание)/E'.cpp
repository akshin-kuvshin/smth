// author: Danila "akshin_" Aksionov

#include <iostream>
#include <vector>
#include <deque>
#include <stack>
using namespace std;
typedef long long int lli;

#define plli                pair<lli, lli>
#define mp(_first, _second) make_pair(_first, _second)
#define pb(_elem)           push_back(_elem)

#define to                  first
#define cost                second

const lli MAX_SIZE = (lli)2e5 + 5LL;

lli T;
lli N;
vector<plli> G[MAX_SIZE];
lli u,
    v,
    w;
lli K;
deque<lli> q;
lli q_prod;
lli d[MAX_SIZE];

void solve();
void dfs(lli, lli);

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin >> T;
    while (T--)
        solve();
    
    return 0;
}

void solve() {
    // input
    cin >> N;
    for (int i = 1; i <= (int)N; ++i)
        G[i].clear();
    cin >> K;
    for (int _ = 0; _ + 1 < (int)N; ++_) {
        cin >> u >> v >> w;
        G[u].pb(mp(v, w));
        G[v].pb(mp(u, w));
    }

    // solution
    q.clear();
    q_prod = 1LL;
    dfs(1LL, -1LL);
    
    // output
    for (int i = 2; i <= (int)N; ++i)
        cout << d[i] << ' ';
    cout << '\n';
    return;
}

void dfs(lli cur, lli prim) {
    stack<lli> tmp;
    while (q_prod > K) {
        lli _front = q.front();
        q.pop_front();

        tmp.push(_front);
        q_prod /= _front;
    }

    d[cur] = (lli)q.size();
    for (plli ns : G[cur]) {
        if (ns.to == prim)
            continue;
        
        q.push_back(ns.cost);
        q_prod *= ns.cost;
        dfs(ns.to, cur);
        q.pop_back();
        q_prod /= ns.cost;
    }

    while (!tmp.empty()) {
        lli _front = tmp.top();
        tmp.pop();

        q.push_front(_front);
        q_prod *= _front;
    }
    return;
}
