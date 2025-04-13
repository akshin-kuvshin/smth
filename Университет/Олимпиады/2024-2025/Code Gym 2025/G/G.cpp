// author: Danila "akshin_" Axyonov

#include <iostream>
#include <unordered_map>
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
    lli a228,
        a229,
        a231,
        a232;
    cin >> a228 >> a229 >> a231 >> a232;

    unordered_map<lli, lli> m;
    ++m[a228 + a229];
    ++m[a231 - a229];
    ++m[a232 - a231];

    lli _max = 0LL;
    for (auto [_, cnt] : m)
        _max = max(_max, cnt);
    cout << _max << '\n';
    
    return;
}
