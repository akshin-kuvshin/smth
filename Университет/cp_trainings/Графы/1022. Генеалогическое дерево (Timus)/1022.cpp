// author: Danila "akshin_" Axyonov

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long int lli;

#define plli                pair<lli, lli>
#define mp(_first, _second) make_pair(_first, _second)
#define pb(_elem)           push_back(_elem)

void solve();
void dfs(const vector<vector<lli>>&, vector<bool>&, vector<lli>&, lli);

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    solve();
    
    return 0;
}

void solve() {
    lli n;
    cin >> n;
    vector<vector<lli>> G(n + 1LL);
    vector<bool> is_son(n + 1LL, false);
    for (int i = 1; i <= (int)n; ++i) {
        lli to;
        cin >> to;
        while (to) {
            G[i].pb(to);
            is_son[to] = true;
            cin >> to;
        }
    }

    vector<bool> used(n + 1LL);
    vector<lli> seq;
    for (lli start = 1LL; start <= n; ++start)
        if (not is_son[start])
            dfs(G, used, seq, start);
    reverse(seq.begin(), seq.end());
    
    for (auto v : seq)
        cout << v << ' ';
    cout << '\n';
    return;
}

void dfs(const vector<vector<lli>> &G, vector<bool> &used, vector<lli> &seq, lli v) {
    for (auto to : G[v]) {
        if (used[to]) continue;
        used[to] = true;
        dfs(G, used, seq, to);
    }
    seq.pb(v);
    return;
}
