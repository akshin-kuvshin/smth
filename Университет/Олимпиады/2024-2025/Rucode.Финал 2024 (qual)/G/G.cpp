// author: Danila "akshin_" Axyonov

#include <iostream>
#include <vector>
#include <set>
#include <queue>
#include <algorithm>
using namespace std;
typedef long long int lli;

#define plli                pair<lli, lli>
#define mp(_first, _second) make_pair(_first, _second)
#define pb(_elem)           push_back(_elem)

const lli MAX_SIZE = (lli)1e6 + 5LL;
// GG
lli N;
lli A[MAX_SIZE];
set<lli> G[MAX_SIZE];
vector<lli> G_copy[MAX_SIZE];
queue<lli> Q;
bool used[MAX_SIZE];
lli primal[MAX_SIZE];
lli best;
queue<plli> Qp;
lli d;

void solve();
void dfs_clean(lli, lli);

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    solve();
    
    return 0;
}

void solve() {
    // Ввод
    cin >> N;
    for (int i = 1; i <= (int)N; ++i)
        cin >> A[i];
    for (int _ = 0; _ + 1 < (int)N; ++_) {
        lli u,
            v;
        cin >> u >> v;
        G[u].insert(v);
        G[v].insert(u);
    }
    for (int i = 1; i <= (int)N; ++i)
        G_copy[i] = vector<lli>(G[i].begin(), G[i].end());

    // Крайний случай
    if (N == 2LL) {
        cout << max(A[1] + A[2] - 1LL, 0LL) << '\n';
        return;
    }

    // Убрали отростки, в которых не было заселённых микрорайонов
    lli root = 1LL;
    for (; !A[root] and root <= N; ++root);
    if (root == N + 1LL) { cout << "0\n"; return; }
    dfs_clean(root, -1LL);

    // Ищем диаметр дерева и берём его середину - она будет являться ЦЕНТРОМ
    lli start = 1LL,
        v1,
        v2;
    for (; !G[start].size(); ++start);
    Q.push(start);
    used[start] = true;
    while (!Q.empty()) {
        lli cur = Q.front();
        Q.pop();
        v1 = cur;

        for (lli nb : G[cur]) {
            if (used[nb]) continue;
            Q.push(nb);
            used[nb] = true;
        }
    }
    Q = queue<lli>(); fill(used + 1LL, used + 1LL + N, false);
    Q.push(v1);
    used[v1] = true;
    primal[v1] = -1LL;
    while (!Q.empty()) {
        lli cur = Q.front();
        Q.pop();
        v2 = cur;

        for (lli nb : G[cur]) {
            if (used[nb]) continue;
            Q.push(nb);
            used[nb] = true;
            primal[nb] = cur;
        }
    }
    lli len = 1LL;
    for (lli _ = v2; _ != v1; _ = primal[_]) ++len;
    lli need = len >> 1;
    best = v2;
    for (int i = 0; i < (int)need; ++i)
        best = primal[best];

    // Считаем расстояние от центра до самой дальней
    fill(used + 1LL, used + 1LL + N, false);
    Qp.push(mp(best, 0LL));
    used[best] = true;
    while (!Qp.empty()) {
        plli cur = Qp.front();
        Qp.pop();

        if (A[cur.first])
            d = max(d, cur.second);

        for (lli nb : G_copy[cur.first]) {
            if (used[nb])
                continue;
            Qp.push(mp(nb, cur.second + 1LL));
            used[nb] = true;
        }
    }
    
    // Вывод
    cout << d << '\n';
    return;
}

void dfs_clean(lli v, lli prim) {
    vector<lli> nbs(G[v].begin(), G[v].end());
    for (lli nb : nbs) {
        if (nb == prim) continue;
        dfs_clean(nb, v);
    }

    if (prim != -1LL and !A[v] and (lli)G[v].size() == 1LL) {
        G[prim].erase(v);
        G[v].erase(prim);
    }
    return;
}
