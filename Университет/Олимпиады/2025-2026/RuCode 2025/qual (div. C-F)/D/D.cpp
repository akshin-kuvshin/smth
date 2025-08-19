// author: Danila "akshin_" Axyonov

#include <iostream>
using namespace std;
using lli = long long int;

#define plli                pair<lli, lli>
#define mp(_first, _second) make_pair(_first, _second)
#define pb(_elem)           push_back(_elem)

void solve();
lli _abs(lli);

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    solve();
    
    return 0;
}

void solve() {
    lli x,
        y,
        r;
    cin >> x >> y >> r;

    if (x * x + y * y < r * r) {
        cout << "5\n";
        return;
    }

    if (not x or not y) {
        cout << "3\n";
        return;
    }
    // now x != 0 and y != 0

    if (_abs(x) < r and _abs(y) < r) {
        cout << "4\n";
        return;
    }
    if (_abs(x) < r or _abs(y) < r) {
        cout << "3\n";
        return;
    }
    if (_abs(x) == r or _abs(y) == r) {
        cout << "2\n";
        return;
    }
    cout << "1\n";
    return;
}

lli _abs(lli num) {
    return (num >= 0LL ? num : -num);
}
