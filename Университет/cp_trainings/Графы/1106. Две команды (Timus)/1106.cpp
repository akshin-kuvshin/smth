// author: Danila "akshin_" Axyonov

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
typedef long long int lli;

#define plli                pair<lli, lli>
#define mp(_first, _second) make_pair(_first, _second)
#define pb(_elem)           push_back(_elem)

void solve();
void bfs(lli, const vector<vector<lli>>&, vector<bool>&, vector<bool>&);

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    solve();
    
    return 0;
}

void solve() {
    lli n;
    cin >> n;
    vector<vector<lli>> G(n);
    for (int i = 0; i < (int)n; ++i) {
        lli ns;
        cin >> ns;
        while (ns) {
            G[i].pb(--ns);
            cin >> ns;
        }
    }

    vector<bool> used(n),
                 team(n);
    for (lli u = 0LL; u < n; ++u)
        if (not used[u])
            bfs(u, G, used, team);
    
    // below we alse can used count(team.begin(), team.end(), true) and 'if (team[u])...'
    cout << count(team.begin(), team.end(), false) << '\n';
    for (lli u = 0LL; u < n; ++u)
        if (not team[u])
            cout << (u + 1LL) << ' ';
    cout << '\n';
    return;
}

void bfs(lli start, const vector<vector<lli>> &G, vector<bool> &used, vector<bool> &team) {
    queue<pair<lli, bool>> Q;
    Q.push(mp(start, false));
    used[start] = true;
    while (not Q.empty()) {
        pair<lli, bool> cur = Q.front();
        Q.pop();
        team[cur.first] = cur.second;
        for (lli ns : G[cur.first]) {
            if (used[ns]) continue;
            Q.push(mp(ns, not cur.second));
            used[ns] = true;
        }
    }
    return;
}
