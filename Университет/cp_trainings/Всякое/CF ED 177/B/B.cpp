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
    lli n,
        k,
        x;
    cin >> n >> k >> x;
    vector<lli> a(n),
                pref(n + 1LL);
    for (int i = 0; i < (int)n; ++i) {
        cin >> a[i];
        pref[i + 1] = pref[i] + a[i];
    }

    lli l = -1LL,
        r = n * k;
    while (l + 1LL < r) {
        lli m = (l + r) >> 1;
        lli s = m / n * pref.back() + pref[m % n];
        if (k * pref.back() - s >= x)
            l = m;
        else // pref.back() - pref[m] < x
            r = m;
    }
    
    cout << r /* == l + 1LL */ << '\n';
    return;
}
