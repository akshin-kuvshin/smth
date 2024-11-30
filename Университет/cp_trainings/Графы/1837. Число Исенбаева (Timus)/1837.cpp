// author: Danila "akshin_" Axyonov

#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <queue>
using namespace std;
typedef long long int lli;

#define plli                pair<lli, lli>
#define mp(_first, _second) make_pair(_first, _second)
#define pb(_elem)           push_back(_elem)

void solve();
lli bfs(string, const map<string, vector<string>>&);

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    solve();
    
    return 0;
}

void solve() {
    map<string, vector<string>> G;

    lli n;
    cin >> n;
    while (n--) {
        string a,
               b,
               c;
        cin >> a >> b >> c;
        G[a].pb(b); G[a].pb(c);
        G[b].pb(a); G[b].pb(c);
        G[c].pb(a); G[c].pb(b);
    }
    
    for (const pair<string, vector<string>> &p : G) {
        cout << p.first << ' ';
        lli res = bfs(p.first, G);
        if (res == -1LL)
            cout << "undefined\n";
        else // res != -1LL
            cout << res << '\n';
    }
    
    return;
}

lli bfs(string start, const map<string, vector<string>> &G) {
    queue<pair<string, lli>> Q;
    map<string, bool> used;

    Q.push(mp(start, 0LL));
    used[start] = true;
    while (not Q.empty()) {
        pair<string, lli> cur = Q.front();
        Q.pop();

        if (cur.first == "Isenbaev")
            return cur.second;

        for (const string &ns : G.at(cur.first)) {
            if (used[ns]) continue;
            Q.push(mp(ns, cur.second + 1LL));
            used[ns] = true;
        }
    }

    return -1LL;
}
