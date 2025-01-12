// author: Danila "akshin_" Axyonov

#include <iostream>
using namespace std;
using lli = long long int;

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
        b;
    cin >> n >> a >> b;

    if (abs(a - b) % 2LL == 0LL)
        cout << "YES\n";
    else
        cout << "NO\n";
    
    return;
}
