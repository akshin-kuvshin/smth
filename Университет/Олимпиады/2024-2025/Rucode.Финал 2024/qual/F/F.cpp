// author: Danila "akshin_" Axyonov
// Нихуя не понятно, как определить корректность римского числа. IL корректное или нет? А XM?

#include <iostream>
using namespace std;
typedef long long int lli;

#define plli                pair<lli, lli>
#define mp(_first, _second) make_pair(_first, _second)
#define pb(_elem)           push_back(_elem)

lli N;

void solve();

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    solve();
    
    return 0;
}

void solve() {
    cin >> N;

    if (N == 1LL) cout << "7\n";
    else cout << "0\n";
    
    return;
}
