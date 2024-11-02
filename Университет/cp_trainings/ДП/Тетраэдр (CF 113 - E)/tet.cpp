// author: Danila "akshin_" Axyonov
// OH MY GOD MEMORY LIMIT 2 TIMES

#include <iostream>
#include <vector>
using namespace std;
typedef long long int lli;

#define plli                pair<lli, lli>
#define mp(_first, _second) make_pair(_first, _second)
#define pb(_elem)           push_back(_elem)

const lli MOD = (lli)1e9 + 7LL,
          V = 4LL;

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

    lli dp0 = 1LL,
        dp1 = 0LL;
    for (int i = 1; i <= (int)N; ++i) {
        lli new_dp0 = (dp1 * (V - 1LL)) % MOD,
            new_dp1 = (dp0 + dp1 * (V - 2LL)) % MOD;
        dp0 = new_dp0, dp1 = new_dp1;
    }
    
    cout << dp0 << '\n';
    return;
}
