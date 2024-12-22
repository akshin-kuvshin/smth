// author: Danila "akshin_" Axyonov

#include <iostream>
using namespace std;
typedef long long int lli;

#define plli                pair<lli, lli>
#define mp(_first, _second) make_pair(_first, _second)
#define pb(_elem)           push_back(_elem)

void solve();

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    lli Q;
    cin >> Q;
    while (Q--)
        solve();
    
    return 0;
}

void solve() {
    lli n,
        a,
        b,
        c;
    cin >> n >> a >> b >> c;

    lli k = n / (a + b + c);
    n -= k * (a + b + c);
    lli res = k * 3LL;
    for (auto d : {a, b, c})
        if (n > 0LL) {
            n -= d;
            ++res;
        }
    cout << res << '\n';
    return;
}
