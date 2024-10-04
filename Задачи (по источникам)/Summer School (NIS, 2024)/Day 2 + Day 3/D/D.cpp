// author: Danila "akshin_" Axyonov

#include <iostream>
using namespace std;
typedef long long int lli;

#define plli                pair<lli, lli>
#define mp(_first, _second) make_pair(_first, _second)
#define pb(_elem)           push_back(_elem)

lli a,
    b;

void solve();

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    solve();
    
    return 0;
}

void solve() {
    cin >> a >> b;

    if (abs(a - b) % 3LL != 0LL)
        cout << "-1\n";
    else // abs(a - b) % 3LL == 0LL
        cout << (min(a, b) / 3LL * 2LL + min(a, b) % 3LL + abs(a - b) / 3LL) << '\n';
    
    return;
}
