// author: Alexander Valeev

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
    
    solve();
    
    return 0;
}

void solve() {
    lli x1, x2, y1, y2;
    cin >> x1 >> y1 >> x2 >> y2;

    lli d = abs(x2 - x1) + abs(y2 - y1) - 1LL;
    if (x1 == x2 && y1 == y2)
        d = 0LL;
    
    cout << d << '\n';
}
