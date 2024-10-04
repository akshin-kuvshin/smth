// author: Danila "akshin_" Aksionov

#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
using namespace std;
typedef long long int lli;

#define plli                pair<lli, lli>
#define mp(_first, _second) make_pair(_first, _second)
#define pb(_elem)           push_back(_elem)

#define to                  first
#define cost                second
#define vertex              first
#define length              second

const lli MAX_SIZE = (lli)5e2 + 5LL,
          INF = (lli)1e18 + 1LL;

class Compare {
public:
    bool operator() (const plli &p1, const plli &p2) const {
        return p1.length <= p2.length;
    }
};

lli N;
vector<plli> G[MAX_SIZE];
lli M,
    u,
    v,
    c;
lli A,
    B;
lli dA[MAX_SIZE],
    dB[MAX_SIZE];
lli stat[MAX_SIZE]; // stat[i] = 0LL or 1LL or 2LL

void solve();
void get_d(lli, lli*);
bool is_there_way();

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    solve();
    
    return 0;
}

void solve() {
    cin >> N >> M;
    while (M--) {
        cin >> u >> v >> c;
        G[u].pb(mp(v, c));
        G[v].pb(mp(u, c));
    }
    cin >> A >> B;
    
    get_d(A, dA);
    get_d(B, dB);

    for (int i = 1; i <= (int)N; ++i)
        if (dA[i] == dB[i])
            stat[i] = 0LL;
        else if (dA[i] < dB[i])
            stat[i] = 1LL;
        else // dA[i] > dB[i]
            stat[i] = 2LL;
    
    if (is_there_way()) {
        cout << "-1\n";
        return;
    }

    for (int i = 1; i <= (int)N; ++i)
        cout << stat[i] << ' ';
    cout << '\n';
    return;
}

void get_d(lli start, lli *d) {
    set<plli, Compare> q;
    bool used[MAX_SIZE];

    fill(d + 1LL, d + 1LL + N, INF);
    fill(used + 1LL, used + 1LL + N, false);

    d[start] = 0LL;
    for (lli i = 1LL; i <= N; ++i)
        q.insert(mp(i, d[i]));
    
    while (!q.empty()) {
        plli cur = *(q.begin());
        q.erase(q.begin());

        if (cur.length == INF)
            break;
        
        used[cur.vertex] = true;
        for (plli ns : G[cur.vertex]) {
            if (used[ns.to])
                continue;
            
            lli new_length = cur.length + ns.cost;
            if (new_length < d[ns.to]) {
                q.erase(mp(ns.to, d[ns.to]));
                d[ns.to] = new_length;
                q.insert(mp(ns.to, d[ns.to]));
            }
        }
    }

    return;
}

bool is_there_way() {
    lli start = A,
        finish = B;
    
    lli q[MAX_SIZE],
        b = 0LL,
        e = 0LL;
    bool used[MAX_SIZE];
    fill(used + 1LL, used + 1LL + N, false);

    q[e++] = start;
    used[start] = true;
    while (b < e) {
        lli cur = q[b++];

        if (cur == finish)
            return true;
        if (stat[cur] == 0LL)
            continue;
        
        for (plli ns : G[cur]) {
            if (used[ns.to])
                continue;
            
            q[e++] = ns.to;
            used[ns.to] = true;
        }
    }

    return false;
}
