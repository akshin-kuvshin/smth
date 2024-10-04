// author: Danila "akshin_" Aksionov

#include <iostream>
using namespace std;
typedef long long int lli;

#define plli                pair<lli, lli>
#define mp(_first, _second) make_pair(_first, _second)
#define pb(_elem)           push_back(_elem)

lli A,
    B;

void solve();
lli gcd_R(lli, lli);
lli lcm(lli, lli);

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    solve();
    
    return 0;
}

void solve() {
    cin >> A >> B;
    cout << lcm(A, B) << '\n';
    return;
}

lli gcd_R(lli n, lli m) {
    return ((n && m) ? gcd_R(m, n % m) : (n | m));
}

lli lcm(lli n, lli m) {
    return n / gcd_R(n, m) * m;
}
