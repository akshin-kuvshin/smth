// author: Danila "akshin_" Axyonov

#include <iostream>
#include <vector>
using namespace std;
typedef long long int lli;

#define plli                pair<lli, lli>
#define mp(_first, _second) make_pair(_first, _second)
#define pb(_elem)           push_back(_elem)

void solve();
lli dfs(lli, const vector<lli>&, vector<bool>&);

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    solve();
    
    return 0;
}

void solve() {
    lli n;
    cin >> n;
    vector<lli> p(n);
    for (int i = 0; i < (int)n; ++i) {
        cin >> p[i];
        --p[i];
    }

    vector<bool> used(n);
    for (lli v = 0LL; v < n; ++v)
        cout << dfs(v, p, used) + 1LL << ' ';
    cout << '\n';
    return;
}

lli dfs(lli v, const vector<lli> &p, vector<bool> &used) {
    if (used[v]) return v;
    used[v] = true;
    lli res = dfs(p[v], p, used);
    used[v] = false;
    return res;
}
