// author: Danila "akshin_" Aksionov

#include <iostream>
using namespace std;
typedef long long int lli;

#define plli                pair<lli, lli>
#define mp(_first, _second) make_pair(_first, _second)
#define pb(_elem)           push_back(_elem)

const lli MAX_SIZE = (lli)1e3 + 5LL;

lli N,
    A[MAX_SIZE];
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
    for (int i = 1; i <= (int)N; ++i)
        cin >> A[i];
    
    dp[0] = 0LL;
    dp[1] = A[1];
    for (int i = 2; i <= (int)N; ++i)
        dp[i] = max(dp[i - 1], dp[i - 2]) + A[i];
    
    cout << dp[N] << '\n';
    return;
}
