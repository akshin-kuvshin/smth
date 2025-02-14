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
        
        lli ind = (lli)(upper_bound(a.begin(), a.end(), x) - a.begin());
        if (ind == 0LL)
            cout << a.front();
        else if (ind == n)
            cout << a.back();
        else { // 0 < ind < n
            lli d1 = abs(x - a[ind - 1LL]),
                d2 = abs(x - a[ind]);
            if (d1 <= d2)
                cout << a[ind - 1LL];
            else
                cout << a[ind];
        }
        cout << '\n';
    }
    
    return;
}
