// author: Danila "akshin_" Aksionov

#include <iostream>
#include <vector>
using namespace std;
typedef long long int lli;

#define plli                pair<lli, lli>
#define mp(_first, _second) make_pair(_first, _second)
#define pb(_elem)           push_back(_elem)

#define ROOT                -1LL

const lli MAX_SIZE = (lli)1e5 + 5LL;

lli N,
    start;
lli A[MAX_SIZE],
    B[MAX_SIZE];
lli u,
    v;
vector<lli> G[MAX_SIZE];
lli q[MAX_SIZE],
    answer;

void solve();
void dfs(lli, lli);

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    solve();
    
    return 0;
}

void solve() {
    cin >> N >> start;
    --start;
    for (int i = 0; i < (int)N; ++i)
        cin >> A[i];
    for (int i = 0; i < (int)N; ++i)
        cin >> B[i];
    for (int _ = 0; _ + 1 < (int)N; ++_) {
        cin >> u >> v;
        --u, --v;
        G[u].pb(v);
        G[v].pb(u);
    }

    q[start] = 1LL;
    dfs(start, ROOT);

    answer = q[0];
    for (int i = 1; i < (int)N; ++i)
        answer = max(answer, q[i]);
    cout << answer << '\n';
    return;
}

void dfs(lli node, lli primal) {
    if (primal != ROOT)
        q[node] = q[primal] + max(A[node] - A[primal], B[node] - B[primal]);

    for (lli ns : G[node]) {
        if (ns == primal)
            continue;
        dfs(ns, node);
    }

    return;
}
