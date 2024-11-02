// author: Danila "akshin_" Axyonov

#include <iostream>
#include <vector>
using namespace std;
typedef long long int lli;

#define plli                pair<lli, lli>
#define mp(_first, _second) make_pair(_first, _second)
#define pb(_elem)           push_back(_elem)

#define d                   first       // some element already has been deleted
#define nd                  second      // none of elements have been deleted

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
    vector<lli> A(N);
    for (lli &elem : A)
        cin >> elem;
    
    vector<pair<lli, lli>> dp(N, {0LL, 0LL});
    dp[0].nd = 1LL;
    dp[0].d = 0LL;
    dp[1].nd = 1LL;
    if (A[0] < A[1]) dp[1].nd = 2LL;
    dp[1].d = 1LL;
    for (int i = 2; i < (int)N; ++i) {
        // for nd
        dp[i].nd = 1LL;
        if (A[i - 1] < A[i]) dp[i].nd = dp[i - 1].nd + 1LL;

        // for d
        dp[i].d = 1LL;
        if (A[i - 1] < A[i]) dp[i].d = dp[i - 1].d + 1LL;
        if (A[i - 2] < A[i]) dp[i].d = max(dp[i].d, dp[i - 2].nd + 1LL);
    }
    
    lli ans = 0LL;
    for (int i = 0; i < (int)N; ++i)
        ans = max(ans, max(dp[i].d, dp[i].nd));
    cout << ans << '\n';

    return;
}
