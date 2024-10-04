// author: Danila "akshin_" Aksionov

#include <iostream>
using namespace std;
typedef long long int lli;

lli A,
    B;
lli spects;

void solve();

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    solve();
    
    return 0;
}

void solve() {
    cin >> A >> B;
    spects += (A / 2LL) * (B / 2LL);
    spects += (A * B - spects * 4LL + 1LL) / 2LL;
    cout << spects << '\n';
    return;
}
