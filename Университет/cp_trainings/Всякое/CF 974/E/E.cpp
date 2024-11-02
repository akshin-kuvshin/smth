// author: Danila "akshin_" Axyonov

#include <iostream>
#include <vector>
#include <set>
using namespace std;
typedef long long int lli;

#define plli                pair<lli, lli>
#define mp(_first, _second) make_pair(_first, _second)
#define pb(_elem)           push_back(_elem)

const lli INF = (lli)1e18 + 1LL;

class Rib {
public:
    lli to;
    lli w;

    Rib(lli __to, lli __w) {
        this->to = __to;
        this->w = __w;
        return;
    }
};

class Node {
public:
    lli v;
    lli d;
    bool h;

    Node(lli __v, lli __d, bool __h) {
        this->v = __v;
        this->d = __d;
        this->h = __h;
        return;
    }

    bool operator <(const Node &n) const {
        if (this->d != n.d)
            return this->d < n.d;
        if (this->h != n.h)
            return this->h > n.h;
        return this->v < n.v;
    }
};

void solve();
vector<lli> dijkstra(lli, const vector<vector<Rib>>&, const vector<bool>&, lli);

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    lli Q;
    cin >> Q;
    while (Q--)
        solve();
    
    return 0;
}

void solve() {
    lli N,
        M,
        H;
    cin >> N >> M >> H;

    vector<bool> horse(N, false);
    while (H--) {
        lli v;
        cin >> v;
        horse[--v] = true;
    }

    vector<vector<Rib>> G(N);
    while (M--) {
        lli from,
            to,
            w;
        cin >> from >> to >> w;
        --from; --to;
        G[from].emplace_back(to, w);
        G[to].emplace_back(from, w);
    }

    vector<lli> d1 = dijkstra(N, G, horse, 0LL),
                d2 = dijkstra(N, G, horse, N - 1LL);
    lli ans = INF;
    for (int i = 0; i < (int)N; ++i)
        ans = min(ans, max(d1[i], d2[i]));
    cout << (ans == INF ? -1LL : ans) << '\n';
    return;
}

vector<lli> dijkstra(lli N, const vector<vector<Rib>> &G, const vector<bool> &horse, lli start) {
    set<Node> S;
    vector<lli> d(N, INF),
                dh(N, INF);
    d[start] = 0LL;
    if (horse[start])
        dh[start] = 0LL;
    for (int i = 0; i < (int)N; ++i) {
        if ((lli)i == start) {
            S.insert(Node(start, 0LL, horse[start]));
            continue;
        }
        S.insert(Node((lli)i, INF, false));
    }

    while (not S.empty()) {
        Node cur = *S.begin();
        S.erase(S.begin());

        if (cur.d == INF)
            break;
        
        for (Rib nb : G[cur.v])
            if (cur.h) {
                if (cur.d + nb.w / 2LL < dh[nb.to]) {
                    S.erase(Node(nb.to, dh[nb.to], true));
                    dh[nb.to] = cur.d + nb.w / 2LL;
                    S.insert(Node(nb.to, dh[nb.to], true));
                }
            } else { // cur.h == false
                if (horse[nb.to]) {
                    if (cur.d + nb.w < dh[nb.to]) {
                        S.erase(Node(nb.to, dh[nb.to], true));
                        dh[nb.to] = cur.d + nb.w;
                        S.insert(Node(nb.to, dh[nb.to], true));
                    }
                } else { // horse[nb.to] == false
                    if (cur.d + nb.w < d[nb.to]) {
                        S.erase(Node(nb.to, d[nb.to], false));
                        d[nb.to] = cur.d + nb.w;
                        S.insert(Node(nb.to, d[nb.to], false));
                    }
                }
            }
    }

    vector<lli> ans(N);
    for (int i = 0; i < (int)N; ++i)
        ans[i] = min(d[i], dh[i]);    
    return ans;
}
