// author: Danila "akshin_" Aksionov

#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;
typedef long long int lli;

#define plli                pair<lli, lli>
#define mp(_first, _second) make_pair(_first, _second)
#define pb(_elem)           push_back(_elem)

#define vertex  first
#define cost    second
#define length  second
#define INF     (lli)1e6
#define ROOT    -1LL
#define NO_WAY  -1LL

const lli MAX_SIZE = (lli)1e2 + 5LL;

class Compare {
public:
    bool operator ()(const plli &p1, const plli &p2) const {
        if (p1.length == p2.length)
            return p1.vertex < p2.vertex;
        return p1.length < p2.length;
    }
};

lli N;
vector<plli> G[MAX_SIZE];
lli start,
    finish;
set<plli, Compare> q;
lli d[MAX_SIZE];
bool used[MAX_SIZE];
lli p[MAX_SIZE];

void solve();
void print_way();

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    solve();
    
    return 0;
}

void solve() {
    cin >> N >> start >> finish;
    for (int i = 1; i <= (int)N; ++i) {
        for (int j = 1; j <= (int)N; ++j) {
            lli cost;
            cin >> cost;
            if (i == j)
                continue;
            if (cost != -1LL)
                G[i].pb(mp((lli)j, cost));
        }
    }
    
    fill(d + 1LL, d + 1LL + N, INF);
    d[start] = 0LL;
    p[start] = ROOT;
    for (int i = 1; i <= (int)N; ++i)
        q.insert(mp(i, d[i]));

    while (!q.empty()) {
        plli current = *(q.begin());
        q.erase(q.begin());

        if (current.length == INF)
            break;

        used[current.vertex] = true;

        if (current.vertex == finish)
            break;
        
        for (plli ns : G[current.vertex]) {
            if (used[ns.vertex])
                continue;

            lli new_length = current.length + ns.cost;
            if (new_length < d[ns.vertex]) {
                q.erase(mp(ns.vertex, d[ns.vertex]));
                d[ns.vertex] = new_length;
                p[ns.vertex] = current.vertex;
                q.insert(mp(ns.vertex, d[ns.vertex]));
            }
        }
    }

    if (used[finish])
        print_way();
    else
        cout << NO_WAY << '\n';
    return;
}

void print_way() {
    vector<lli> way;
    for (int v = (int)finish; v != ROOT; v = (int)p[v])
        way.pb(v);
    for (int i = (int)way.size() - 1; i >= 0; --i)
        cout << way[i] << ' ';
    cout << '\n';
    return;
}
