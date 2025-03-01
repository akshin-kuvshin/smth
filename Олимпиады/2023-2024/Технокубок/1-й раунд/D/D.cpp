// author: Danila "akshin_" Aksionov

#include <iostream>
using namespace std;
typedef long long int lli;

#define plli                pair<lli, lli>
#define mp(_first, _second) make_pair(_first, _second)
#define pb(_elem)           push_back(_elem)

const lli MAX_SIZE = (lli)1e4 + 5LL,
          MOD = 998244353LL;

lli N;
lli dp[MAX_SIZE][3][2];
// P.S.: dp[i][j][k] = кол-во i-значных чисел, которые дают остаток j при делении на 3 и не содержат в себе нечётной цифры, если k == 0, или содержат её, если k == 1.
// Также у всех них отсутствуют ведущие нули, а также любая перестановка цифр в этом числе даёт такое число x, что gcd(x, 10) > 1.
// Отсюда следует, что все числа состоят из цифр 0, 2, 4, 5, 6, 8.

void solve();

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    solve();
    
    return 0;
}

void solve() {
    cin >> N;
    
    // Памятка
    // Доступные цифры: 0, 2, 4, 5, 6, 8
    // mod 3 == 0:      0, 6
    // mod 3 == 1:      4
    // mod 3 == 2:      2, 5, 8
    dp[1][0][0] = 1LL; // 6
    dp[1][0][1] = 0LL;
    dp[1][1][0] = 1LL; // 4
    dp[1][1][1] = 0LL;
    dp[1][2][0] = 2LL; // 2, 8
    dp[1][2][1] = 1LL; // 5
    for (int i = 2; i <= (int)N; ++i) {
        dp[i][0][0] = 2LL * dp[i - 1][0][0] + 2LL * dp[i - 1][1][0] + dp[i - 1][2][0];
        dp[i][0][1] = 2LL * dp[i - 1][0][1] + 2LL * dp[i - 1][1][1] + dp[i - 1][2][1] + (dp[i - 1][1][0] + dp[i - 1][1][1]);
        dp[i][1][0] = 2LL * dp[i - 1][1][0] + 2LL * dp[i - 1][2][0] + dp[i - 1][0][0];
        dp[i][1][1] = 2LL * dp[i - 1][1][1] + 2LL * dp[i - 1][2][1] + dp[i - 1][0][1] + (dp[i - 1][2][0] + dp[i - 1][2][1]);
        dp[i][2][0] = 2LL * dp[i - 1][2][0] + 2LL * dp[i - 1][0][0] + dp[i - 1][1][0];
        dp[i][2][1] = 2LL * dp[i - 1][2][1] + 2LL * dp[i - 1][0][1] + dp[i - 1][1][1] + (dp[i - 1][0][0] + dp[i - 1][0][1]);

        dp[i][0][0] %= MOD;
        dp[i][0][1] %= MOD;
        dp[i][1][0] %= MOD;
        dp[i][1][1] %= MOD;
        dp[i][2][0] %= MOD;
        dp[i][2][1] %= MOD;
    }
    // P.S.: там где k == 0, слагаемые идут так:
    // 1) 2LL * dp[i - 1][j][0] => это варианты, куда можно приписать 0 или 6;
    // 2) + 2LL * dp[i - 1][j + 1][0] => это варианты, куда можно приписать 2 или 8;
    // 3) + dp[i - 1][j + 2][0] => это варианты, куда можно приписать 4.
    // Там, где k == 1, слагаемые идут так:
    // 1) 2LL * dp[i - 1][j][1] => это варианты, куда можно приписать 0 или 6;
    // 2) + 2LL * dp[i - 1][j + 1][1] => это варианты, куда можно приписать 2 или 8;
    // 3) + dp[i - 1][j + 2][1] => это варианты, куда можно приписать 4;
    // 4) + (dp[i - 1][j + 1][0] + dp[i - 1][j + 1][1]) => это варианты, куда можно приписать 5.
    
    cout << ((dp[N][1][1] + dp[N][2][1]) % MOD) << '\n';
    return;
}
