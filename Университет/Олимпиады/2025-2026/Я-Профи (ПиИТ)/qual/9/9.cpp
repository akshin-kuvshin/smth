// author: Danila "akshin_" Axyonov

#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;
using lli = long long int;
using plli = pair<lli, lli>;

#define mp(_first, _second) make_pair(_first, _second)
#define pb(_elem)           push_back(_elem)

void solve();

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    lli q;
    cin >> q;
    while (q--)
        solve();

    return 0;
}

void solve() {
    lli n;
    cin >> n;
    vector<lli> a(n);
    for (auto& ai : a)
        cin >> ai;
    
    lli ans = 0LL;
    unordered_map<lli, lli> m;
    lli l = 0LL;
    for (lli r = 0LL; r < n; ++r) {
        ++m[a[r]];
        if (m[a[r]] == 2LL) {
            while (a[l] != a[r])
                --m[a[l++]];
            --m[a[l++]];
        }
        ans += r - l + 1LL;
    }

    cout << ans << '\n';
}
