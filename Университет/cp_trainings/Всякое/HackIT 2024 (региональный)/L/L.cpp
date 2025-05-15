// author: Danila "akshin_" Axyonov

#include <iostream>
#include <vector>
#include <algorithm>
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
    lli s,
        d;
    cin >> s >> d;
    lli n;
    cin >> n;
    vector<plli> w(n);
    for (auto& [a, b] : w)
        cin >> a >> b;
    sort(w.begin(), w.end());

    lli blocks = 0LL,
        gold = 0LL;
    for (auto [a, b] : w) {
        lli k = d / b;
        k = max(min(k, s - blocks), 0LL);
        blocks += k;
        gold += k * a;
    }
    cout << (blocks == s ? gold : -1LL) << '\n';

    return;
}
