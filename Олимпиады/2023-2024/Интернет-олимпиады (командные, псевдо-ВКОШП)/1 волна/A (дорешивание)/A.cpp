// author: Danila "akshin_" Aksionov
// P.S.: начал виртуальное соревнование только ради этой задачи.
// Сдал)
// В оригинальном контесте решил 5 задач (B, C, D, F, L) с общим штрафом 771 и 39-ым местом.
// На задачу A не хватило времени(

#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#define INF (lli)1e18
#define vertex first
#define cost second
#define length second
using namespace std;
typedef long long int lli;

const lli MAX_SIZE = (lli)3e5;

class Compare {
public:
    bool operator ()(const pair<lli, lli> &p1, const pair<lli, lli> &p2) const {
        if (p1.length == p2.length)
            return p1.vertex < p2.vertex;
        return p1.length < p2.length;
    }
};

lli N,
    N2,
    x,
    M1,
    M2,
    start,
    finish;
vector<pair<lli, lli>> G[MAX_SIZE]; // vertex - cost
set<pair<lli, lli>, Compare> q; // vertex - length
lli d[MAX_SIZE];
bool used[MAX_SIZE];

void solve();
void input();
void solution();

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    solve();
    
    return 0;
}

void solve() {
    input();
    solution(); 
    return;
}

void input() {
    cin >> N;
    N2 = (N << 1);

    cin >> x;
    for (int i = 1; i <= (int)N; ++i) {
        G[i].push_back(make_pair(i + N, x));
        G[i + N].push_back(make_pair(i, x));
    }

    cin >> M1;
    while (M1--) {
        lli u,
            v,
            c;
        cin >> u >> v >> c;
        G[u].push_back(make_pair(v, c));
        G[v].push_back(make_pair(u, c));
    }

    cin >> M2;
    while (M2--) {
        lli u,
            v,
            c;
        cin >> u >> v >> c;
        u += N;
        v += N;
        G[u].push_back(make_pair(v, c));
        G[v].push_back(make_pair(u, c));
    }

    cin >> start >> finish;
    finish += N;

    return;
}

void solution() {
    fill(d + 1LL, d + 1LL + 2LL * N, INF);
    fill(used + 1LL, used + 1LL + 2LL * N, false);

    d[start] = 0LL;
    for (int i = 1; i <= (lli)N2; ++i)
        q.insert(make_pair(i, d[i]));

    while (!q.empty()) {
        pair<lli, lli> current = *(q.begin());
        q.erase(q.begin());

        if (current.vertex == finish) {
            cout << current.length << '\n';
            return;
        }
        if (current.length == INF)
            break;
        
        used[current.vertex] = true;
        for (pair<lli, lli> n : G[current.vertex]) {
            if (used[n.vertex])
                continue;
            
            lli new_length = current.length + n.cost;
            if (new_length < d[n.vertex]) {
                q.erase(make_pair(n.vertex, d[n.vertex]));
                d[n.vertex] = new_length;
                q.insert(make_pair(n.vertex, d[n.vertex]));
            }
        }
    }

    cout << "-1\n";
    return;
}
