// author: Danila "akshin_" Aksionov

#include <iostream>
using namespace std;
typedef long long int lli;

#define plli                pair<lli, lli>
#define mp(_first, _second) make_pair(_first, _second)
#define pb(_elem)           push_back(_elem)

const lli MAX_SIZE = (lli)1e6 + 5LL;

lli N;
lli dp[MAX_SIZE];

void solve();

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    solve();
    
    return 0;
}

void solve() {
    cin >> N;

    dp[1] = 0LL;
    for (lli i = 2LL; i <= N; ++i) {
        dp[i] = dp[i - 1] + 1LL;
        if (i % 2LL == 0LL)
            dp[i] = min(dp[i], dp[i / 2LL] + 1LL);
        if (i % 3LL == 0LL)
            dp[i] = min(dp[i], dp[i / 3LL] + 1LL);
    }
    
    cout << dp[N] << '\n';
    return;
}
