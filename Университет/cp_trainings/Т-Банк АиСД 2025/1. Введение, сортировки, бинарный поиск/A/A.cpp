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
    vector<lli> a(n);
    for (int i = 0; i < (int)n; ++i)
        cin >> a[i];
    
    while (q--) {
        lli x;
        cin >> x;
        auto bs_res = lower_bound(a.begin(), a.end(), x);
        if (bs_res < a.end() and *bs_res == x)
            cout << "YES\n";
        else
            cout << "NO\n";
    }
    
    return;
}
