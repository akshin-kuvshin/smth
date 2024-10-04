// author: Danila "akshin_" Axyonov
// FINAL VERSION

#include <iostream>
#include <vector>
#include <cmath>
#include <queue>
using namespace std;
typedef long long int lli;

#define pii                 pair<int, int>
#define mp(_first, _second) make_pair(_first, _second)
#define pb(_elem)           push_back(_elem)

#define x                   first
#define y                   second

const int MAX_SIZE = (int)2e3 + 5,
          INF = (int)1e9 + 1;

int N,
    M;
char A[MAX_SIZE][MAX_SIZE];
pii X;
vector<pii> I;

int max_path;
queue<pair<pii, int>> q;
bool used[MAX_SIZE][MAX_SIZE];

void solve();

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    solve();
    
    return 0;
}

void solve() {
    cin >> N >> M;
    for (int i = 0; i < N; ++i)
        for (int j = 0; j < M; ++j) {
            cin >> A[i][j];
            if (A[i][j] == 'X')
                X = mp(i, j);
            else if (A[i][j] == 'I')
                I.pb(mp(i, j));
        }
    
    // на всякий случай
    if (I.empty()) {
        cout << "0\n";
        return;
    }

    // checking for mod 2
    int mod = (abs(X.x - I[0].x) + abs(X.y - I[0].y)) % 2;
    for (pii i : I)
        if ((abs(X.x - i.x) + abs(X.y - i.y)) % 2 != mod) {
            cout << "-1\n";
            return;
        }
    
    // bfs
    max_path = -INF;

    q.push(mp(X, 0));
    used[X.x][X.y] = true;
    while (!q.empty()) {
        pair<pii, int> tmp = q.front();
        q.pop();
        
        int i = tmp.first.x,
            j = tmp.first.y,
            len = tmp.second;

        if (A[i][j] == 'I') {
            max_path = max(max_path, len);
            continue;
        }
        
        // up
        if (i - 1 >= 0 and A[i - 1][j] != 'B' and !used[i - 1][j]) {
            q.push(mp(mp(i - 1, j), len + 1));
            used[i - 1][j] = true;
        }
        // down
        if (i + 1 < N and A[i + 1][j] != 'B' and !used[i + 1][j]) {
            q.push(mp(mp(i + 1, j), len + 1));
            used[i + 1][j] = true;
        }
        // left
        if (j - 1 >= 0 and A[i][j - 1] != 'B' and !used[i][j - 1]) {
            q.push(mp(mp(i, j - 1), len + 1));
            used[i][j - 1] = true;
        }
        // right
        if (j + 1 < M and A[i][j + 1] != 'B' and !used[i][j + 1]) {
            q.push(mp(mp(i, j + 1), len + 1));
            used[i][j + 1] = true;
        }
    }
    
    for (pii i : I)
        if (!used[i.x][i.y]) {
            cout << "-1\n";
            return;
        }
    
    cout << ((lli)max_path * (lli)I.size()) << '\n';
    return;
}
