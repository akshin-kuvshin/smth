// author: Danila "akshin_" Aksionov

#include <iostream>
#include <vector>
#include <queue>
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
#define NO_WAY  -1LL

const lli MAX_SIZE = (lli)1e2 + 5LL;

class Compare {
public:
    bool operator ()(const plli &p1, const plli &p2) const {
        if (p1.length == p2.length)
            return p1.vertex > p2.vertex;
        return p1.length > p2.length;
    }
};

lli N;
vector<plli> G[MAX_SIZE];
lli start,
    finish;
priority_queue<plli, vector<plli>, Compare> q;
lli d[MAX_SIZE];
bool used[MAX_SIZE];

void solve();

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
    q.push(mp(start, d[start]));

    while (!q.empty()) {
        plli current = q.top();
        q.pop();
        
        if (used[current.vertex])
            continue;
        used[current.vertex] = true;

        if (current.vertex == finish)
            break;

        for (plli ns : G[current.vertex]) {
            if (used[ns.vertex])
                continue;

            lli new_length = current.length + ns.cost;
            if (new_length < d[ns.vertex]) {
                d[ns.vertex] = new_length;
                q.push(mp(ns.vertex, d[ns.vertex]));
            }
        }
    }

    cout << (used[finish] ? d[finish] : NO_WAY) << '\n';
    return;
}
