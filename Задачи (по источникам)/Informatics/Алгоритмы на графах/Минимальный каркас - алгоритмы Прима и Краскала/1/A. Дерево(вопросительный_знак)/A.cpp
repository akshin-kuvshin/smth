// author: Danila "akshin_" Aksionov

#include <iostream>
using namespace std;
typedef long long int lli;

#define plli                pair<lli, lli>
#define mp(_first, _second) make_pair(_first, _second)
#define pb(_elem)           push_back(_elem)

const lli MAX_SIZE = (lli)1e2 + 5LL;

lli N,
    G[MAX_SIZE][MAX_SIZE];
bool used[MAX_SIZE];
lli ribs_number,
    visited_vertexes_number;

void solve();
void dfs(lli);

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    solve();
    
    return 0;
}

void solve() {
    cin >> N;
    for (int from = 0; from < (int)N; ++from)
        for (int to = 0; to < (int)N; ++to) {
            cin >> G[from][to];
            ribs_number += G[from][to];
        }
    ribs_number >>= 1;
    
    if (ribs_number != N - 1LL) {
        cout << "NO\n";
        return;
    }
    
    dfs(0);
    if (visited_vertexes_number != N) {
        cout << "NO\n";
        return;
    }
    
    cout << "YES\n";
    return;
}

void dfs(lli cur) {
    used[cur] = true;
    ++visited_vertexes_number;

    for (int to = 0; to < (int)N; ++to) {
        if (!G[cur][to])
            continue;
        if (used[to])
            continue;
        dfs((lli)to);
    }

    return;
}
