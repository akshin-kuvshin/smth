// author: Danila "akshin_" Axyonov

#include <iostream>
using namespace std;
using lli = long long int;
using plli = pair<lli, lli>;

#define mp(_first, _second) make_pair(_first, _second)
#define pb(_elem)           push_back(_elem)

void solve();

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}

void solve() {
    lli k;
    cin >> k;

    lli res = 0LL,
        cur = 1LL;
    while (k) {
        res += (k % 2LL) * cur;
        k /= 2LL;
        cur *= 3LL;
    }
    
    cout << res << '\n';
}
