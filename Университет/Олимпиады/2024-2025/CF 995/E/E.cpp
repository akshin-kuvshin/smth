// author: Danila "akshin_" Axyonov

#include <iostream>
#include <vector>
#include <map>
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
    lli n,
        k;
    cin >> n >> k;
    vector<lli> a(n),
                b(n);
    for (int i = 0; i < (int)n; ++i)
        cin >> a[i];
    for (int i = 0; i < (int)n; ++i)
        cin >> b[i];
    
    map<lli, unordered_multiset<lli>> l;
    for (int i = 0; i < (int)n; ++i) {
        l[a[i]].insert(0LL);
        l[a[i] + 1LL].insert(1LL);
        l[b[i]].insert(2LL);
        l[b[i] + 1LL].insert(3LL);
    }

    lli ans = 0LL;
    lli cnt = 0LL,
        buyers = n;
    for (const auto [cost, S] : l) {
        lli c1 = S.count(1LL),
            c3 = S.count(3LL);
        cnt += c1 - c3;
        buyers -= c3;
        if (cnt <= k)
            ans = max(ans, cost * buyers);
    }
    cout << ans << '\n';
    return;
}
