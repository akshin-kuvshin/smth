// author: Danila "akshin_" Axyonov

#include <iostream>
using namespace std;
typedef long long int lli;

#define plli                pair<lli, lli>
#define mp(_first, _second) make_pair(_first, _second)
#define pb(_elem)           push_back(_elem)

lli Q;
lli x,
    cur_y,
    _max;

void solve();
lli gcd_R(lli, lli);

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin >> Q;
    while (Q--)
        solve();
    
    return 0;
}

void solve() {
    cin >> x;

    cur_y = -1LL;
    _max = -1LL;
    for (lli y = 1LL; y < x; ++y)
        if (gcd_R(x, y) + y > _max) {
            cur_y = y;
            _max = gcd_R(x, y) + y;
        }
    
    cout << cur_y << '\n';
    return;
}

lli gcd_R(lli a, lli b) {
    return ((a && b) ? gcd_R(b, a % b) : (a | b));
}
