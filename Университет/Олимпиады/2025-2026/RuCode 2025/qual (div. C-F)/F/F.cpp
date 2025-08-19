// author: Danila "akshin_" Axyonov

#include <iostream>
#include <vector>
using namespace std;
using lli = long long int;

#define plli                pair<lli, lli>
#define mp(_first, _second) make_pair(_first, _second)
#define pb(_elem)           push_back(_elem)

#define VOWEL               0LL
#define CONSONANT           1LL
#define J                   2LL
#define SPECIAL             3LL

const lli MOD = (lli)1e9 + 7LL;

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

    vector<vector<lli>> dp(n, vector<lli>(4LL));
    dp[0][VOWEL] = 10LL;
    dp[0][CONSONANT] = 20LL;
    dp[0][J] = 1LL;
    dp[0][SPECIAL] = 0LL;

    for (int i = 1; i < (int)n; ++i) {
        dp[i][VOWEL] = (((dp[i - 1][CONSONANT] + dp[i - 1][J] + dp[i - 1][SPECIAL]) % MOD) * 10LL) % MOD;
        dp[i][CONSONANT] = (dp[i - 1][VOWEL] * 20LL) % MOD;
        dp[i][J] = dp[i - 1][VOWEL];
        dp[i][SPECIAL] = (dp[i - 1][CONSONANT] * 2LL) % MOD;
    }

    lli ans = 0LL;
    for (int i = 0; i < 4; ++i)
        ans = (ans + dp.back()[i]) % MOD;
    cout << ans << '\n';
    
    return;
}
