// author: Danila "akshin_" Aksionov

#include <iostream>
#include <vector>
#include <queue>
using namespace std;
typedef long long int lli;

#define plli                pair<lli, lli>
#define mp(_first, _second) make_pair(_first, _second)
#define pb(_elem)           push_back(_elem)

const lli MAX_SIZE = (lli)1e5 + 5LL;

lli N;
vector<lli> G[MAX_SIZE];
lli M,
    u,
    v;
lli start;

bool cons[MAX_SIZE]; // правильный ли текст у i-того пользователя
queue<lli> q;
bool used[MAX_SIZE];

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
        cin >> u >> v;
        G[u].pb(v);
        G[v].pb(u);
    }
    cin >> start;

    cons[start] = true;
    q.push(start);
    used[start] = true;
    while (!q.empty()) {
        lli cur = q.front();
        q.pop();

        for (lli ns : G[cur]) {
            if (used[ns])
                continue;
            
            cons[ns] = !cons[cur];
            q.push(ns);
            used[ns] = true;
        }
    }
    
    for (int i = 1; i <= (int)N; ++i)
        ans += (lli)cons[i];
    cout << ans << '\n';
    return;
}
