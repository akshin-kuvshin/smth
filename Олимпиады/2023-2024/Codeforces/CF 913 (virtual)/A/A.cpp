// author: Danila "akshin_" Axyonov

#include <iostream>
using namespace std;
typedef long long int lli;

#define plli                pair<lli, lli>
#define mp(_first, _second) make_pair(_first, _second)
#define pb(_elem)           push_back(_elem)

lli Q;
char x0,
     y0;

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
    cin >> x0 >> y0;

    for (char x = 'a'; x <= 'h'; ++x) {
        if (x == x0)
            continue;
        cout << x << y0 << '\n';
    }
    for (char y = '1'; y <= '8'; ++y) {
        if (y == y0)
            continue;
        cout << x0 << y << '\n';
    }

    return;
}
