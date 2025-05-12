// author: Danila "akshin_" Axyonov

#include <iostream>
#include <vector>
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
    lli n;
    cin >> n;
    vector<lli> a(n);
    for (lli& ai : a)
        cin >> ai;
    
    vector<lli> pref_max(n),
                suf_sum(n);
    pref_max.front() = a.front();
    for (int i = 1; i < (int)n; ++i)
        pref_max[i] = max(pref_max[i - 1], a[i]);
    suf_sum.back() = a.back();
    for (int i = (int)n - 2; i >= 0; --i)
        suf_sum[i] = suf_sum[i + 1] + a[i];
    
    for (int i = (int)n - 1; i > 0; --i) {
        lli res = suf_sum[i];
        if (pref_max[i - 1] > a[i])
            res += pref_max[i - 1] - a[i];
        cout << res << ' ';
    }
    cout << suf_sum.front() << '\n';
    
    return;
}
