// author: Danila "akshin_" Axyonov

#include <iostream>
#include <vector>
#include <queue>
using namespace std;
typedef long long int lli;

lli N,
    M;
vector<vector<lli>> G;
vector<bool> used;
lli good,
    all;

void solve();
lli bfs(lli);
lli gcd_R(lli, lli);

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}

void solve() {
    cin >> N >> M;
    G.resize(N); used.resize(N, false);
    while (M--) {
        lli a,
            b;
        cin >> a >> b;
        --a; --b;
        G[a].push_back(b);
        G[b].push_back(a);
    }

    for (int i = 0; i < (int)N; ++i) {
        if (used[i]) continue;
        lli res = bfs((lli)i);
        good += res * (res - 1LL) / 2LL;
    }

    all = N * (N - 1LL) / 2LL;

    lli g = gcd_R(good, all);
    good /= g;
    all /= g;
    cout << good << ' ' << all << '\n';

    return;
}

lli bfs(lli start) {
    lli res = 0LL;
    queue<lli> q;
    q.push(start);
    used[start] = true;
    while (not q.empty()) {
        lli cur = q.front();
        q.pop();
        ++res;
        for (lli nb : G[cur]) {
            if (used[nb]) continue;
            q.push(nb);
            used[nb] = true;
        }
    }
    return res;
}

lli gcd_R(lli a, lli b) {
    return ((a && b) ? gcd_R(b, a % b) : (a | b));
}
