// author: Danila "akshin_" Axyonov

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long int lli;

#define plli                pair<lli, lli>
#define mp(_first, _second) make_pair(_first, _second)
#define pb(_elem)           push_back(_elem)

const lli INF = (lli)1e13 + 1LL,
          MAX_SPEED = (lli)1e3;

void solve();

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    solve();
    
    return 0;
}

void solve() {
    lli K;
    cin >> K;
    vector<lli> A(K + 1LL);
    A[0] = 1LL;
    for (int i = 1; i <= (int)K; ++i)
        cin >> A[i];
    
    vector<vector<lli>> dp(A[K] + 1LL, vector<lli>(MAX_SPEED + 5LL, INF));
    dp[1][0] = 0LL;
    for (int __i = 0; __i + 1 <= (int)K; ++__i) {
        lli b = A[__i],
            e = A[__i + 1];
        for (lli i = b + 1LL; i <= e; ++i)
            for (lli v = 1LL; v <= min(i - b, MAX_SPEED); ++v)
                dp[i][v] = min(dp[i - v][v - 1LL], min(dp[i - v][v], dp[i - v][v + 1LL])) + 1LL;
    }
    lli last = A[K];
    lli ans = *min_element(dp[last].begin(), dp[last].end());
    cout << ans << '\n';
    return;
}
