// author: Danila "akshin_" Aksionov

#include <iostream>
using namespace std;
typedef long long int lli;

#define plli                pair<lli, lli>
#define mp(_first, _second) make_pair(_first, _second)
#define pb(_elem)           push_back(_elem)

const lli MAX_SIZE = 30LL + 5LL;

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

    dp[0] = 1LL;
    dp[1] = 1LL;
    dp[2] = 2LL;
    for (int i = 3; i <= (int)N; ++i)
        dp[i] = dp[i - 1] + dp[i - 2] + dp[i - 3];
    
    cout << dp[N] << '\n';
    return;
}
