// author: Danila "akshin_" Axyonov

#include <iostream>
using namespace std;
typedef long long int lli;

#define plli                pair<lli, lli>
#define mp(_first, _second) make_pair(_first, _second)
#define pb(_elem)           push_back(_elem)

lli Q;
lli N,
    K,
    d;

void solve();

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin >> Q;
    while (Q--)
        solve();
    
    return 0;
}

void solve() {
    cin >> N >> K;
    d = K % 4LL;
    if (d == 0LL or (d == 1LL and N % 2LL == 0LL) or (d == 3LL and N % 2LL == 1LL))
        cout << "YES\n";
    else
        cout << "NO\n";
    return;
}
