// author: Danila "akshin_" Axyonov
// FINAL VERSION

#include <iostream>
#include <algorithm> // for std::fill
#include <queue>
#include <set>
using namespace std;
typedef long long int lli;

#define plli                pair<lli, lli>
#define mp(_first, _second) make_pair(_first, _second)
#define pb(_elem)           push_back(_elem)

const lli N_max = (lli)1e7 + 5LL,
          M = 3LL;

class Node {
public:
    lli i;
    lli j;
    lli c;

    Node(lli __i, lli __j, lli __c) {
        i = __i;
        j = __j;
        c = __c;
        return;
    }
};

lli N;
char A[N_max][M];

queue<Node> q;
bool used[N_max][M];

void solve();
lli bfs(lli);

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    solve();
    
    return 0;
}

void solve() {
    cin >> N;
    for (int i = 0; i < (int)N; ++i)
        for (int j = 0; j < (int)M; ++j)
            cin >> A[i][j];
    
    plli a1 = mp(bfs(0LL), 1LL),
         a2 = mp(bfs(1LL), 2LL),
         a3 = mp(bfs(2LL), 3LL);
    
    set<plli> S;
    if (A[0][0] == '.' and a1.first != -1LL)
        S.insert(a1);
    if (A[0][1] == '.' and a2.first != -1LL)
        S.insert(a2);
    if (A[0][2] == '.' and a3.first != -1LL)
        S.insert(a3);
    
    if (S.empty())
        cout << "-1\n";
    else
        cout << S.begin()->second << '\n' << S.begin()->first << '\n';

    return;
}

lli bfs(lli start_j) {
    q = queue<Node>();
    for (int i = 0; i < (int)N; ++i)
        used[i][0] = used[i][1] = used[i][2] = false;
    
    q.emplace(0LL, start_j, 0LL);
    while (!q.empty()) {
        Node cur = q.front();
        q.pop();

        if (cur.i == N - 1LL)
            return cur.c;
        
        if (cur.j == 0LL) {
            // down
            if (A[cur.i + 1LL][0] == '.' and !used[cur.i + 1LL][0]) {
                q.emplace(cur.i + 1LL, 0LL, cur.c);
                used[cur.i + 1LL][0] = true;
            }
            // right
            if (A[cur.i][1] == '.' and !used[cur.i][1]) {
                q.emplace(cur.i, 1LL, cur.c + 1LL);
                used[cur.i][1] = true;
            }
        } else if (cur.j == 1LL) {
            // down
            if (A[cur.i + 1LL][1] == '.' and !used[cur.i + 1LL][1]) {
                q.emplace(cur.i + 1LL, 1LL, cur.c);
                used[cur.i + 1LL][1] = true;
            }
            // left
            if (A[cur.i][0] == '.' and !used[cur.i][0]) {
                q.emplace(cur.i, 0LL, cur.c + 1LL);
                used[cur.i][0] = true;
            }
            // right
            if (A[cur.i][2] == '.' and !used[cur.i][2]) {
                q.emplace(cur.i, 2LL, cur.c + 1LL);
                used[cur.i][2] = true;
            }
        } else { // cur.j == 2LL
            // down
            if (A[cur.i + 1LL][2] == '.' and !used[cur.i + 1LL][2]) {
                q.emplace(cur.i + 1LL, 2LL, cur.c);
                used[cur.i + 1LL][2] = true;
            }
            // right
            if (A[cur.i][1] == '.' and !used[cur.i][1]) {
                q.emplace(cur.i, 1LL, cur.c + 1LL);
                used[cur.i][1] = true;
            }
        }
    }

    return -1LL;
}
