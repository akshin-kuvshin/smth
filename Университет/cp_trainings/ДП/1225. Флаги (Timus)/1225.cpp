// author: Danila "akshin_" Axyonov

#include <iostream>
#include <vector>
using namespace std;
typedef long long int lli;

#define plli                pair<lli, lli>
#define mp(_first, _second) make_pair(_first, _second)
#define pb(_elem)           push_back(_elem)

#define WHITE               0
#define RED                 1
#define W_BLUE              2
#define R_BLUE              3

void solve();

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    solve();
    
    return 0;
}

void solve() {
    lli N;
    cin >> N;
    vector<vector<lli>> dp(N + 1LL, vector<lli>(4, 0LL));

    dp[1][WHITE] = dp[1][RED] = 1LL;
    for (int i = 2; i <= (int)N; ++i) {
        dp[i][WHITE] = dp[i - 1][RED] + dp[i - 1][R_BLUE];
        dp[i][RED] = dp[i - 1][WHITE] + dp[i - 1][W_BLUE];
        dp[i][W_BLUE] = dp[i - 1][WHITE];
        dp[i][R_BLUE] = dp[i - 1][RED];
    }

    lli answer = dp[N][WHITE] + dp[N][RED];
    cout << answer << '\n';
    
    return;
}
