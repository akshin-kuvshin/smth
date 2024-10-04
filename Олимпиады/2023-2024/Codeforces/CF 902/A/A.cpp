// author: Danila "akshin_" Aksionov

#include <iostream>
using namespace std;
typedef long long int lli;

#define plli                pair<lli, lli>
#define mp(_first, _second) make_pair(_first, _second)
#define pb(_elem)           push_back(_elem)

lli Q;
lli N,
    elem,
    sum;

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
    sum = 0LL;

    cin >> N;
    while (--N) {
        cin >> elem;
        sum += elem;
    }
    
    cout << (0LL - sum) << '\n';
    return;
}
