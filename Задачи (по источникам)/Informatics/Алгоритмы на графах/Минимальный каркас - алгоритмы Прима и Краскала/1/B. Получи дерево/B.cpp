// author: Danila "akshin_" Axyonov

#include <iostream>
#include <vector>
#include <queue>
using namespace std;
typedef long long int lli;

#define plli                pair<lli, lli>
#define mp(_first, _second) make_pair(_first, _second)
#define pb(_elem)           push_back(_elem)

const lli MAX_SIZE = (lli)1e2 + 5LL;

lli N;
vector<lli> G[MAX_SIZE];
lli M,
    u,
    v;

queue<lli> q;
bool used[MAX_SIZE];
lli cnt;

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

    q.push(1LL);
    used[1] = true;
    while (cnt < N - 1LL) {
        lli cur = q.front();
        q.pop();

        for (lli ns : G[cur]) {
            if (used[ns])
                continue;
            q.push(ns);
            used[ns] = true;
            ++cnt;
            cout << cur << ' ' << ns << '\n';
        }
    }
    
    return;
}
