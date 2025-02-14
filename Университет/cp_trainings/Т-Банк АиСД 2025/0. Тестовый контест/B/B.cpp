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
        k;
    cin >> n >> k;
    vector<lli> a(n);
    for (int i = 0; i < (int)n; ++i)
        cin >> a[i];
    sort(a.begin(), a.end());
    if (k == 0LL) {
        if (a.front() == 1LL)
            cout << "-1";
        else // a.front() > 1LL
            cout << "1";
    } else if (k == n) {
        cout << "1000000000";
    } else { // 1 <= k <= n - 1
        --k; // now 0 <= k < n - 1
        if (a[k] == a[k + 1LL])
            cout << "-1";
        else // a[k] < a[k + 1LL]
            cout << a[k];
    }
    cout << '\n';
    return;
}
