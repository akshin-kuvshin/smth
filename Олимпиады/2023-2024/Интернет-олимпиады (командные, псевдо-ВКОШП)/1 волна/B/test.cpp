// author: Danila "akshin_" Aksionov

#include <iostream>
using namespace std;
typedef long long int lli;

void solve();
lli gcd_R(lli, lli);
lli lcm(lli, lli);
lli lcm_N(lli);

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    solve();
    
    return 0;
}

void solve() { 
    for (lli N = 1LL; N <= 50LL; ++N)
        cout << N << ' ' << lcm_N(N) << '\n';
    return;
}

lli gcd_R(lli a, lli b) {
    return ((a && b) ? gcd_R(b, a % b) : (a | b));
}

lli lcm(lli a, lli b) {
    return a / gcd_R(a, b) * b;
}

lli lcm_N(lli N) {
    lli result = 1LL;
    for (lli num = 2LL; num <= N; ++num)
        result = lcm(result, num);
    return result;
}
