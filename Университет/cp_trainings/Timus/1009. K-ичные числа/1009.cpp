// author: Danila "akshin_" Axyonov

#include <iostream>
using namespace std;
typedef long long int lli;

#define plli                pair<lli, lli>
#define mp(_first, _second) make_pair(_first, _second)
#define pb(_elem)           push_back(_elem)

const lli MAX_SIZE = 20LL;

lli N,
    K,
    dp[MAX_SIZE][2];

void solve();

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    solve();
    
    return 0;
}

void solve() {
    cin >> N >> K;

    dp[1][0] = K - 1LL;
    dp[1][1] = 0LL;
    for (int i = 2; i <= (int)N; ++i) {
        dp[i][0] = (dp[i - 1][0] + dp[i - 1][1]) * (K - 1LL);
        dp[i][1] = dp[i - 1][0];
    }
    
    cout << (dp[N][0] + dp[N][1]) << '\n';
    return;
}
