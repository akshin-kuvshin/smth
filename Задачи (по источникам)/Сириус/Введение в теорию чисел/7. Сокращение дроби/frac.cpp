// author: Danila "akshin_" Aksionov

#include <iostream>
#include <cmath>
using namespace std;
typedef long long int lli;

#define plli                pair<lli, lli>
#define mp(_first, _second) make_pair(_first, _second)
#define pb(_elem)           push_back(_elem)

lli A,
    B,
    gcd;

void solve();
lli gcd_R(lli, lli);

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    solve();
    
    return 0;
}

void solve() {
    cin >> A >> B;
    gcd = gcd_R(abs(A), B);
    A /= gcd;
    B /= gcd;
    cout << A << ' ' << B << '\n';
    return;
}

lli gcd_R(lli n, lli m) {
    return ((n && m) ? gcd_R(m, n % m) : (n | m));
}
