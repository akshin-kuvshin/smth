// author: Danila "akshin_" Axyonov

#include <iostream>
#include <algorithm>
using namespace std;
typedef long long int lli;

#define plli                pair<lli, lli>
#define mp(_first, _second) make_pair(_first, _second)
#define pb(_elem)           push_back(_elem)

const lli W_MAX = (lli)1e4 + 5LL,
          N_MAX = (lli)3e2 + 5LL;

lli W,
    N,
    _ws[N_MAX], // in this version of problem w[i] equals to c[i]
    dp[N_MAX][W_MAX];

void solve();

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    solve();
    
    return 0;
}

void solve() {
    cin >> W >> N;
    for (int i = 1; i <= (int)N; ++i)
        cin >> _ws[i];
    
    for (lli _n = 1LL; _n <= N; ++_n) {
        for (lli _w = 1LL; _w < min(_ws[_n], W + 1LL); ++_w)
            dp[_n][_w] = dp[_n - 1LL][_w];
        for (lli _w = _ws[_n]; _w <= W; ++_w)
            dp[_n][_w] = max(dp[_n - 1LL][_w], dp[_n - 1LL][_w - _ws[_n]] + _ws[_n]);
    }
    
    cout << dp[N][W] << '\n';
    return;
}
