// author: Danila "akshin_" Axyonov

#include <iostream>
#include <deque>
#include <algorithm>
using namespace std;
typedef long long int lli;

#define plli                pair<lli, lli>
#define mp(_first, _second) make_pair(_first, _second)
#define pb(_elem)           push_back(_elem)

#define x                   first
#define y                   second

const lli MAX_SIZE = (lli)1e3 + 5LL,
          INF = (lli)1e18 + 1LL;

lli Q;
lli N,
    M;
char A[MAX_SIZE][MAX_SIZE];

deque<plli> q;
lli d[MAX_SIZE][MAX_SIZE];

void solve();

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin >> Q;
    while (Q--)
        solve();
    
    return 0;
}

void solve() {
    cin >> N >> M;
    for (int i = 0; i < (int)N; ++i)
        for (int j = 0; j < (int)M; ++j)
            cin >> A[i][j];
    
    q.clear();
    for (int i = 0; i < (int)N; ++i)
        fill(d[i], d[i] + M, INF);

    d[0][0] = 0LL;
    q.push_back(mp(0LL, 0LL));

    while (!q.empty()) {
        plli cur = q.front();
        q.pop_front();
        
        for (plli d_cord : {mp(-1LL, 0LL), mp(1LL, 0LL), mp(0LL, -1LL), mp(0LL, 1LL)}) {
            plli ns = mp(cur.x + d_cord.x, cur.y + d_cord.y);
            if (ns.x < 0LL or N <= ns.x or ns.y < 0LL or M <= ns.y)
                continue;
            
            lli cost = (A[cur.x][cur.y] == A[ns.x][ns.y] ? 0LL : 1LL);

            if (d[cur.x][cur.y] + cost < d[ns.x][ns.y]) {
                d[ns.x][ns.y] = d[cur.x][cur.y] + cost;
                if (cost == 0LL)
                    q.push_front(ns);
                else
                    q.push_back(ns);
            }
        }
    }
    
    cout << d[N - 1LL][M - 1LL] << '\n';
    return;
}
