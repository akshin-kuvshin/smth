// author: Danila "akshin_" Axyonov

#include <iostream>
#include <vector>
#include <deque>
using namespace std;
typedef long long int lli;

#define plli                pair<lli, lli>
#define mp(_first, _second) make_pair(_first, _second)
#define pb(_elem)           push_back(_elem)

#define v                   first
#define len                 second

const lli MAX_SIZE = (lli)1e3 + 5LL,
          INF = (lli)1e18 + 1LL;
const vector<plli> D = {{-1LL, 0LL},
                        {-1LL, 1LL},
                        {0LL, 1LL},
                        {1LL, 1LL},
                        {1LL, 0LL},
                        {1LL, -1LL},
                        {0LL, -1LL},
                        {-1LL, -1LL}};

lli N,
    M;
char A[MAX_SIZE][MAX_SIZE];
vector<plli> G[MAX_SIZE * MAX_SIZE];

lli Q,
    x1,
    y1,
    x2,
    y2;

void solve();
lli get_ind(lli, lli);
lli bfs01(lli, lli);

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    solve();
    
    return 0;
}

void solve() {
    cin >> N >> M;
    for (lli i = 0LL; i < N; ++i)
        for (lli j = 0LL; j < M; ++j)
            cin >> A[i][j];
    
    for (lli i = 0LL; i < N; ++i)
        for (lli j = 0LL; j < M; ++j)
            for (lli k = 0LL; k < (lli)D.size(); ++k) {
                plli ns = mp(i + D[k].first, j + D[k].second);
                if (ns.first < 0LL or N <= ns.first or ns.second < 0LL or M <= ns.second)
                    continue;
                G[get_ind(i, j)].pb(mp(get_ind(ns.first, ns.second), ((lli)(A[i][j] - '0') == k ? 0LL : 1LL)));
            }
    
    cin >> Q;
    while (Q--) {
        cin >> x1 >> y1 >> x2 >> y2;
        --x1, --y1, --x2, --y2;
        cout << bfs01(get_ind(x1, y1), get_ind(x2, y2)) << '\n';
    }

    return;
}

lli get_ind(lli x, lli y) { return x * M + y; }

lli bfs01(lli start, lli finish) {
    deque<lli> q;
    vector<lli> d(N * M, INF);

    d[start] = 0LL;
    q.push_back(start);

    while (!q.empty()) {
        lli cur = q.front();
        q.pop_front();

        for (plli ns : G[cur])
            if (d[cur] + ns.len < d[ns.v]) {
                d[ns.v] = d[cur] + ns.len;
                if (ns.len == 0LL)
                    q.push_front(ns.v);
                else // ns.len == 1LL
                    q.push_back(ns.v);
            }
    }

    return d[finish];
}
