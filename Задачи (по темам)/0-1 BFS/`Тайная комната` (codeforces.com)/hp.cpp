// author: Danila "akshin_" Axyonov

#include <iostream>
#include <deque>
#include <algorithm>
#include <vector>
using namespace std;
typedef long long int lli;

#define plli                pair<lli, lli>
#define mp(_first, _second) make_pair(_first, _second)
#define pb(_elem)           push_back(_elem)

const lli MAX_SIZE = (lli)1e3 + 5LL,
          INF = (lli)1e18 + 1LL, // раньше здесь было (lli)1e2 + 1LL... я даун.
          UP = 0LL,
          RIGHT = 1LL,
          DOWN = 2LL,
          LEFT = 3LL;

class Node {
public:
    lli x;
    lli y;
    lli dir;

    Node() : x(-1LL), y(-1LL), dir(-1LL) {}

    Node(lli _x, lli _y, lli _dir) : x(_x), y(_y), dir(_dir) {}
};

lli N,
    M;
char A[MAX_SIZE][MAX_SIZE];

deque<Node> q;
lli d[MAX_SIZE][MAX_SIZE][4];
lli ans;

void solve();

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
            fill(d[i][j], d[i][j] + 4, INF);
    fill(d[N - 1LL][M], d[N - 1LL][M] + 4, INF);
    
    d[0][0][RIGHT] = 0LL;
    q.emplace_back(0LL, 0LL, RIGHT);

    while (!q.empty()) {
        Node cur = q.front();
        q.pop_front();

        if (A[cur.x][cur.y] == '.') {
            Node ns;
            switch (cur.dir) {
                case UP:
                    ns.x = cur.x - 1LL;
                    ns.y = cur.y;
                    break;
                
                case RIGHT:
                    ns.x = cur.x;
                    ns.y = cur.y + 1LL;
                    break;
                
                case DOWN:
                    ns.x = cur.x + 1LL;
                    ns.y = cur.y;
                    break;
                
                case LEFT:
                    ns.x = cur.x;
                    ns.y = cur.y - 1LL;
                    break;
            }
            ns.dir = cur.dir;

            if ((ns.x < 0LL or N <= ns.x or ns.y < 0LL or M <= ns.y) and not (ns.x == N - 1LL and ns.y == M))
                continue;

            // если что, cur.dir == ns.dir
            if (d[cur.x][cur.y][cur.dir] < d[ns.x][ns.y][ns.dir]) {
                d[ns.x][ns.y][ns.dir] = d[cur.x][cur.y][cur.dir];
                q.push_front(ns);
            }
        } else { // A[cur.x][cur.y] == '#'
            vector<Node> NS = {{cur.x - 1LL, cur.y, UP},
                               {cur.x, cur.y + 1LL, RIGHT},
                               {cur.x + 1LL, cur.y, DOWN},
                               {cur.x, cur.y - 1LL, LEFT}};
            for (Node ns : NS) {
                if ((ns.x < 0LL or N <= ns.x or ns.y < 0LL or M <= ns.y) and not (ns.x == N - 1LL and ns.y == M))
                    continue;
                
                lli len = (cur.dir == ns.dir ? 0LL : 1LL);
                if (d[cur.x][cur.y][cur.dir] + len < d[ns.x][ns.y][ns.dir]) {
                    d[ns.x][ns.y][ns.dir] = d[cur.x][cur.y][cur.dir] + len;
                    if (len == 0LL)
                        q.push_front(ns);
                    else // len == 1LL
                        q.push_back(ns);
                }
            }
        }
    }
    
    ans = d[N - 1LL][M][RIGHT];
    cout << (ans == INF ? -1LL : ans) << '\n';
    return;
}
