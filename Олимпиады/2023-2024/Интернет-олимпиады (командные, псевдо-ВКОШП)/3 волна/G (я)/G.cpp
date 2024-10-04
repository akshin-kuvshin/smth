// author: Danila "akshin_" Axyonov

#include <iostream>
#include <set>
#include <vector>
using namespace std;
typedef long long int lli;

#define plli                pair<lli, lli>
#define mp(_first, _second) make_pair(_first, _second)
#define pb(_elem)           push_back(_elem)

#define l                   first
#define r                   second
#define seg                 first
#define ind                 second

const lli MAX_SIZE = (lli)2e5 + 5LL;

lli N;
plli tmp;
multiset<pair<plli, lli>> S;
vector<lli> ans[MAX_SIZE];
lli top;

void solve();

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    solve();
    
    return 0;
}

void solve() {
    cin >> N;
    for (int i = 1; i <= (int)N; ++i) {
        cin >> tmp.l >> tmp.r;
        S.insert(mp(tmp, (lli)i));
    }

    while (!S.empty()) {
        pair<plli, lli> cur = *S.begin();
        S.erase(S.begin());
        ans[top].pb(cur.ind);

        multiset<pair<plli, lli>>::iterator it;
        while ((it = S.lower_bound(mp(mp(cur.seg.r + 1LL, 0LL), 0LL))) != S.end()) {
            cur = *it;
            S.erase(it);
            ans[top].pb(cur.ind);
        }

        ++top;
    }

    cout << top << '\n';
    for (int i = 0; i < (int)top; ++i) {
        cout << ans[i].size() << '\n';
        for (lli j : ans[i])
            cout << j << ' ';
        cout << '\n';
    }
    
    return;
}
