// author: Danila "akshin_" Aksionov

#include <iostream>
using namespace std;
typedef long long int lli;

#define plli                pair<lli, lli>
#define mp(_first, _second) make_pair(_first, _second)
#define pb(_elem)           push_back(_elem)

const lli _time = 720LL;

lli S,
    K,
    B,
    D,
    P,
    T;
lli for_each;
lli ans;

void solve();

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    solve();
    
    return 0;
}

void solve() {
    cin >> S >> K >> B >> D >> P >> T;
    for_each = max(S, max(K, max(5LL * B, max(2LL * D, P)))) + 1LL + T;
    ans = _time / for_each;
    cout << ans << '\n';
    return;
}
