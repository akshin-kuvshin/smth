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
    lli n,
        q;
    cin >> n >> q;
    vector<lli> a(n),
                k(q);
    for (lli& ai : a)
        cin >> ai;
    sort(a.begin(), a.end());
    for (lli& ki : k)
        cin >> ki;

    lli art = a.back() + 1LL;
    for (lli ki : k) {
        lli m = *upper_bound(a.begin(), a.end(), ki);
        if (art <= 2LL * m)
            cout << art << '\n';
        else // art > 2LL * m
            cout << "0\n";
    }
    
    return;
}
