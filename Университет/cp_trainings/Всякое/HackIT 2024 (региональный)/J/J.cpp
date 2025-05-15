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
    lli n;
    cin >> n;
    vector<lli> v(n);
    for (lli& vi : v)
        cin >> vi;
    sort(v.begin(), v.end(), greater<lli>());

    vector<lli> pref(n + 1LL);
    for (int i = 0; i < (int)n; ++i)
        pref[i + 1] = pref[i] + v[i];

    lli q;
    cin >> q;
    while (q--) {
        lli x;
        cin >> x;
        cout << (lli)(lower_bound(pref.begin(), pref.end(), x) - pref.begin()) << '\n';
    }
    
    return;
}
