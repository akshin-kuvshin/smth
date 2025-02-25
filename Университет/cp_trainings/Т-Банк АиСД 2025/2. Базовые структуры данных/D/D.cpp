// author: Danila "akshin_" Axyonov

#include <iostream>
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
    lli q;
    cin >> q;

    stack<plli> stats;
    lli prev,
        cnt,
        ans = 0LL;
    {
        --q;
        lli color;
        cin >> color;

        prev = color;
        cnt = 1LL;
    }
    while (q--) {
        lli color;
        cin >> color;
        
        if (color == prev)
            ++cnt;
        else if ( /* color != prev and */ cnt >= 3LL) {
            ans += cnt;

            if (not stats.empty() and color == stats.top().first) {
                prev = color;
                cnt = stats.top().second + 1LL;
                stats.pop();
            } else {
                prev = color;
                cnt = 1LL;
            }
        } else { // color != prev and cnt < 3LL
            if (prev != -1LL)
                stats.push(mp(prev, cnt));
            prev = color;
            cnt = 1LL;
        }
    }
    if (cnt >= 3LL)
        ans += cnt;
    
    cout << ans << '\n';
    return;
}
