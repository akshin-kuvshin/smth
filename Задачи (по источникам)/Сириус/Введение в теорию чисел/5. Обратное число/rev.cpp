// author: Danila "akshin_" Aksionov

#include <iostream>
using namespace std;
typedef long long int lli;

#define plli                pair<lli, lli>
#define mp(_first, _second) make_pair(_first, _second)
#define pb(_elem)           push_back(_elem)

lli Q;
lli a,
    p;

void solve();
lli _pow(lli, lli);

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin >> Q;
    while (Q--)
        solve();
    
    return 0;
}

void solve() {
    cin >> p >> a;
    cout << _pow(a, p - 2LL) << '\n';
    return;
}

lli _pow(lli base, lli ptr) {
    if (ptr == 0LL)
        return 1LL;
    if (ptr % 2LL == 0LL) {
        lli tmp = _pow(base, ptr / 2LL);
        return (tmp * tmp) % p;
    }
    return (base * _pow(base, ptr - 1LL)) % p;
}
