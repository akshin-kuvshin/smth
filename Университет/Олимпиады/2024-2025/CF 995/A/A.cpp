// author: Danila "akshin_" Axyonov

#include <iostream>
#include <vector>
using namespace std;
typedef long long int lli;

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
    lli n;
    cin >> n;
    vector<lli> a(n),
                b(n);
    for (int i = 0; i < (int)n; ++i)
        cin >> a[i];
    for (int i = 0; i < (int)n; ++i)
        cin >> b[i];
    
    lli ans = 0LL;
    for (int i = 0; i + 1 < (int)n; ++i)
        if (a[i] > b[i + 1])
            ans += a[i] - b[i + 1];
    ans += a.back();
    
    cout << ans << '\n';
    return;
}
