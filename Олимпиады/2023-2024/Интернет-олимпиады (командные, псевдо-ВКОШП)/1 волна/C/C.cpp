// author: Danila "akshin_" Aksionov

#include <iostream>
#include <vector>
#include <queue>
#define vertex first
#define req second
using namespace std;
typedef long long int lli;

const lli MAX_SIZE = (lli)1e5;

class Comparator {
public:
    bool operator ()(const pair<lli, lli> &p1, const pair<lli, lli> &p2) const {
        return p1.req > p2.req;
    }
};

lli N,
    A[MAX_SIZE + 5LL],
    power,
    M;
vector<pair<lli, lli>> G[MAX_SIZE + 5LL];
lli S;
bool used[MAX_SIZE + 5LL]; // раньше тут был lli
priority_queue<pair<lli, lli>, vector<pair<lli, lli>>, Comparator> q;

void solve();

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    solve();
    
    return 0;
}

void solve() {
    cin >> N >> M >> S;
    for (int i = 1; i <= (int)N; ++i)
        cin >> A[i];
    while (M--) {
        lli u,
            v,
            w;
        cin >> u >> v >> w;
        G[u].push_back(make_pair(v, w));
        G[v].push_back(make_pair(u, w));
    }

    used[S] = true;
    power += A[S];
    for (pair<lli, lli> _n : G[S])
        q.push(_n);

    while (!q.empty()) {
        pair<lli, lli> current = q.top();
        q.pop();

        if (used[current.vertex])
            continue;
        if (power < current.req)
            break;
        
        used[current.vertex] = true;
        power += A[current.vertex];
        for (pair<lli, lli> _n : G[current.vertex])
            if (!used[_n.vertex])
                q.push(_n);
    }
    
    cout << power << '\n';
    return;
}
