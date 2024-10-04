// author: Danila "akshin_" Aksionov

#include <iostream>
using namespace std;
typedef long long int lli;

lli N,
    M;

lli gcd_R(lli, lli);

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N >> M;
    cout << gcd_R(N, M) << '\n';

    return 0;
}

lli gcd_R(lli x, lli y) {
    return ((x && y) ? gcd_R(y, x % y) : (x | y));
}
