// author: Danila "akshin_" Axyonov

#include <iostream>
#include <vector>
#include <unordered_set>
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
    size_t n;
    cin >> n;
    vector<plli> a(n);
    for (size_t i = 0ULL; i < n; ++i)
        cin >> a[i].first >> a[i].second;
    
    vector<lli> u(2ULL * n + 1ULL);
    unordered_multiset<lli> S;
    for (auto [l, r] : a)
        if (l == r) {
            u[l] = 1LL;
            S.insert(l);
        }
    vector<lli> pu(u.size() + 1ULL);
    pu[0] = 0LL;
    for (size_t i = 0ULL; i < u.size(); ++i)
        pu[i + 1ULL] = pu[i] + u[i];
    
    for (auto [l, r] : a) {
        if (l == r) {
            cout << ((S.count(l) == 1ULL) ? 1 : 0);
            continue;
        }

        ++r;
        lli cu = pu[r] - pu[l];
        // cout << "l=" << l << " r=" << r << " cu=" << cu << '\n';
        if (cu < r - l) cout << 1;
        else cout << 0;
    }
    cout << '\n';
    return;
}
