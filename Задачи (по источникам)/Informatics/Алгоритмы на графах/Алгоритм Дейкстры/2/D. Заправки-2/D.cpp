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

#define e       0LL
#define f       1LL

#define NO_WAY  -1LL

const lli MAX_SIZE = (lli)1e2 + 5LL,
          INF = (lli)1e18;

class __Vertex {
public:
    lli vertex;
    lli type;
    lli length;

    __Vertex(lli new_vertex, lli new_type, lli new_length) {
        vertex = new_vertex;
        type = new_type;
        length = new_length;
        return;
    }
};

lli N,
    cost[MAX_SIZE];
lli M,
    u,
    v;
lli start,
    finish;
vector<lli> G[MAX_SIZE];
lli d[2][MAX_SIZE];
lli used[2][MAX_SIZE];

class Compare {
public:
    bool operator ()(const __Vertex &v1, const __Vertex &v2) const {
        if (v1.length != v2.length)
            return v1.length < v2.length;
        if (v1.type != v2.type)
            return v1.type < v2.type;
        return v1.vertex < v2.vertex;
    }
};
set<__Vertex, Compare> q;

void input();
void solve();

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    input();
    solve();
    
    return 0;
}

void input() {
    cin >> N;
    for (int i = 0; i < (int)N; ++i)
        cin >> cost[i];
    cin >> M;
    while (M--) {
        cin >> u >> v;
        --u, --v;
        G[u].pb(v);
        G[v].pb(u);
    }
    return;
}

void solve() {
    q.clear();
    fill(d[e], d[e] + N, INF);
    fill(d[f], d[f] + N, INF);
    fill(used[e], used[e] + N, false);
    fill(used[f], used[f] + N, false);

    start = 0LL;
    finish = N - 1LL;

    d[e][start] = 0LL;
    for (int i = 0; i < (int)N; ++i)
        q.insert(__Vertex((lli)i, e, d[e][i]));
    for (int i = 0; i < (int)N; ++i)
        q.insert(__Vertex((lli)i, f, d[f][i]));
    
    while (!q.empty()) {
        __Vertex current = *(q.begin());
        q.erase(q.begin());

        if (current.length == INF)
            break;
        
        used[current.type][current.vertex] = true;
        if (current.vertex == finish)
            break;
        
        if (current.type == e) {        // currently we have NOT fuel in canister

            for (lli ns : G[current.vertex]) {

                if (!used[e][ns]) {     // опция "заправить бак"
                    lli new_length = current.length + cost[current.vertex];
                    if (new_length < d[e][ns]) {
                        q.erase(__Vertex(ns, e, d[e][ns]));
                        d[e][ns] = new_length;
                        q.insert(__Vertex(ns, e, d[e][ns]));
                    }
                }

                if (!used[f][ns]) {     // опция "заправить бак и канистру"
                    lli new_length = current.length + 2LL * cost[current.vertex];
                    if (new_length < d[f][ns]) {
                        q.erase(__Vertex(ns, f, d[f][ns]));
                        d[f][ns] = new_length;
                        q.insert(__Vertex(ns, f, d[f][ns]));
                    }
                }

            }

        } else { // current.type == b   // currently we have fuel in canister

            for (lli ns : G[current.vertex]) {

                if (!used[e][ns]) {     // опция "перелить бензин из канистры в бак"
                    lli new_length = current.length;
                    if (new_length < d[e][ns]) {
                        q.erase(__Vertex(ns, e, d[e][ns]));
                        d[e][ns] = new_length;
                        q.insert(__Vertex(ns, e, d[e][ns]));
                    }
                }

                if (!used[f][ns]) {
                    lli new_length = current.length + cost[current.vertex];
                    if (new_length < d[f][ns]) {
                        q.erase(__Vertex(ns, f, d[f][ns]));
                        d[f][ns] = new_length;
                        q.insert(__Vertex(ns, f, d[f][ns]));
                    }
                }

            }

        }
    }
    
    // Рассматриваем именно вариант, когда мы доехали до finish'а с пустой канистрой,
    // потому что этот вариант всегда стоит меньше, чем доехать с полной канистрой.
    cout << (used[e][finish] ? d[e][finish] : NO_WAY) << '\n';
    return;
}
