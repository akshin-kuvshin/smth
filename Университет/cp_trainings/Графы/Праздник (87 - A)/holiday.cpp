// author: Danila "akshin_" Axyonov

#include <iostream>
#include <vector>
using namespace std;
typedef long long int lli;

#define plli                pair<lli, lli>
#define mp(_first, _second) make_pair(_first, _second)
#define pb(_elem)           push_back(_elem)

void solve();
lli max_depth(lli, const vector<vector<lli>>&, lli);

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    solve();
    
    return 0;
}

void solve() {
    int N;
    cin >> N;
    vector<lli> P(N);
    for (int i = 0; i < (int)N; ++i) {
        cin >> P[i];
        if (P[i] != -1LL) --P[i];
    }
    
    vector<vector<lli>> G(N);
    for (int i = 0; i < (int)N; ++i) {
        if (P[i] == -1LL) continue;
        G[P[i]].pb((lli)i);
    }

    lli ans = 0LL;
    for (int i = 0; i < (int)N; ++i) {
        if (P[i] != -1LL) continue;
        ans = max(ans, max_depth(N, G, (lli)i));
    }
    
    cout << ans << '\n';
    return;
}

lli max_depth(lli N, const vector<vector<lli>> &G, lli v) {
    lli cur_depth = 1LL;
    for (lli ns : G[v])
        cur_depth = max(cur_depth, max_depth(N, G, ns) + 1LL);
    return cur_depth;
}
