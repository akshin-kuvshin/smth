// author: Danila "akshin_" Aksionov

#include <iostream>
using namespace std;
typedef long long int lli;

#define plli                pair<lli, lli>
#define mp(_first, _second) make_pair(_first, _second)
#define pb(_elem)           push_back(_elem)

const lli MAX_SIZE = (lli)1e3 + 5LL,
          INF = (lli)1e18 + 1LL;

lli N,
    M,
    A[MAX_SIZE][MAX_SIZE];
lli dp[MAX_SIZE][MAX_SIZE];
lli _max = -INF;
plli ind = {-1LL, -1LL};

void solve();

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    solve();
    
    return 0;
}

void solve() {
    cin >> N >> M;
    for (int i = 1; i <= (int)N; ++i)
        for (int j = 1; j <= (int)M; ++j)
            cin >> A[i][j];
    
    for (int i = (int)N; i > 0; --i)
        for (int j = (int)M; j > 0; --j)
            dp[i][j] = A[i][j] + A[i + 1][j] + A[i + 1][j + 1] + dp[i + 2][j + 1];
    
    for (int i = 1; i <= (int)N; ++i)
        for (int j = 1; j <= (int)M; ++j)
            if (_max < dp[i][j]) {
                _max = dp[i][j];
                ind = mp((lli)i, (lli)j);
            }
    
    cout << _max << '\n' << ind.first << ' ' << ind.second << '\n';
    return;
}
