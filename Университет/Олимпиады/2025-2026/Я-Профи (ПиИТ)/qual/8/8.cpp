// author: Danila "akshin_" Axyonov

#include <iostream>
#include <vector>
using namespace std;
using lli = long long int;
using plli = pair<lli, lli>;

#define mp(_first, _second) make_pair(_first, _second)
#define pb(_elem)           push_back(_elem)

const lli MOD = 1'000'000'007LL;

void solve();

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}

void solve() {
    lli n;
    cin >> n;

    /* 0) оканчивающиеся на 'a';
     * 1) оканчивающиеся на 'b' или 'c', при этом 'a' ещё не было;
     * 2) оканчивающиеся на 'c', при этом 'a' уже была, но после последней 'a' ещё не было 'b';
     * 3) оканчивающиеся на 'b' или 'c', при этом 'a' уже была, и после последней 'a' уже была 'b';
     */

    vector<vector<lli>> dp(n, vector<lli>(4));
    dp[0] = {1LL, 2LL, 0LL, 0LL};
    for (int i = 1; i < (int)n; ++i) {
        dp[i][0] = (dp[i - 1][1] + dp[i - 1][3]) % MOD;
        dp[i][1] = (dp[i - 1][1] * 2LL) % MOD;
        dp[i][2] = (dp[i - 1][0] + dp[i - 1][2]) % MOD;
        dp[i][3] = (dp[i - 1][0] + dp[i - 1][2] + dp[i - 1][3] * 2LL) % MOD;
    }

    lli ans = 0LL;
    for (int i = 0; i < 4; ++i)
        ans += dp.back()[i];
    ans %= MOD;
    cout << ans << '\n';
}
