// author: Danila "akshin_" Axyonov

#include <iostream>
#include <string>
#include <set>
#include <map>
#include <queue>
using namespace std;
typedef long long int lli;

#define plli                pair<lli, lli>
#define mp(_first, _second) make_pair(_first, _second)
#define pb(_elem)           push_back(_elem)

void solve();
void bfs(string, const map<string, set<string>>&, map<string, lli>&);

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    solve();
    
    return 0;
}

void solve() {
    map<string, set<string>> G;

    lli n;
    cin >> n;
    while (n--) {
        string a,
               b,
               c;
        cin >> a >> b >> c;
        G[a].insert(b); G[a].insert(c);
        G[b].insert(a); G[b].insert(c);
        G[c].insert(a); G[c].insert(b);
    }

    // It turns out that there is can be no 'Isenbaev' in any team
    if (not G.contains("Isenbaev")) {
        for (const pair<string, set<string>> &p : G)
            cout << p.first << " undefined\n";
        return;
    }
    
    map<string, lli> ress;
    bfs("Isenbaev", G, ress);
    for (const pair<string, lli> &p : ress) {
        cout << p.first << ' ';
        if (p.second == -1LL)
            cout << "undefined\n";
        else // p.second != -1LL
            cout << p.second << '\n';
    }
    
    return;
}

void bfs(string start, const map<string, set<string>> &G, map<string, lli> &ress) {
    queue<pair<string, lli>> Q;
    map<string, bool> used;
    for (const pair<string, set<string>> &p : G)
        ress[p.first] = -1LL;

    Q.push(mp(start, 0LL));
    used[start] = true;
    while (not Q.empty()) {
        pair<string, lli> cur = Q.front();
        Q.pop();

        ress[cur.first] = cur.second;

        for (const string &ns : G.find(cur.first)->second) {
            if (used[ns]) continue;
            Q.push(mp(ns, cur.second + 1LL));
            used[ns] = true;
        }
    }
    return;
}
