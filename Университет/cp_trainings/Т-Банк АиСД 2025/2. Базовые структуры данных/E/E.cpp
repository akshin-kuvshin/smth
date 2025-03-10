// author: Danila "akshin_" Axyonov

#include <iostream>
#include <vector>
#include <stack>
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
    vector<lli> a(n);
    for (auto& x : a) {
        cin >> x;
        --x;
    }
    
    lli ind = 0LL,
        cur = 0LL;
    stack<lli> t;
    vector<bool> used(n);
    vector<plli> ans;

    t.push(a[ind]);
    used[a[ind]] = true;
    ++ind;
    ans.pb(mp(1LL, 1LL));

    while (cur < n)
        if (used[cur]) {
            if (t.top() != cur) {
                cout << "0\n";
                return;
            }

            t.pop();
            if (ans.back().first == 2LL)
                ++ans.back().second;
            else // ans.back().first == 1LL
                ans.pb(mp(2LL, 1LL));
            ++cur;
        } else { // not used[cur]
            t.push(a[ind]);
            used[a[ind]] = true;
            ++ind;
            if (ans.back().first == 1LL)
                ++ans.back().second;
            else // ans.back().first == 2LL
                ans.pb(mp(1LL, 1LL));
        }
    
    cout << ans.size() << '\n'; // изначально забыл вывести размер ans-а...(((((
    for (auto [cmd, cnt] : ans)
        cout << cmd << ' ' << cnt << '\n';
    return;
}
