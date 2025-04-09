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
    
    solve();
    
    return 0;
}

void solve() {
    lli f,
        m,
        c,
        s;
    cin >> f >> m >> c >> s;

    bool flag = ((1LL + c * m) * s <= f * 100LL * m);
    cout << (flag ? "Yes" : "No") << '\n';
    
    return;
}
