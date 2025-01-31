// author: Danila "akshin_" Axyonov

#include <iostream>
#include <vector>
#include <map>
using namespace std;
using lli = long long int;

#define plli                pair<lli, lli>
#define mp(_first, _second) make_pair(_first, _second)
#define pb(_elem)           push_back(_elem)

const lli INF = (lli)1e18 + 1LL;

lli m,
    k;
map<lli, lli> cnt;
lli ans;

void solve();
lli f(map<lli, lli>::iterator cur, lli min_cnt_before, lli len);

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    solve();
    
    return 0;
}

void solve() {
    lli n;
    cin >> n >> m >> k;
    cnt[-INF] = INF;
    for (int _ = 0; _ < (int)n; ++_) {
        lli a,
            c;
        cin >> a >> c;
        cnt[a] = c;
    }

    f(cnt.begin(), cnt.begin()->second, 0LL);
    cout << ans << '\n';
    
    return;
}

// Что за хуйню я написал
lli f(map<lli, lli>::iterator cur, lli min_cnt_before, lli len) {
    lli deleted = 0LL;
    for (auto it = cnt.lower_bound(cur->first + k);
         it != cnt.end() and deleted < min_cnt_before and m > 0LL;
         it = cnt.lower_bound(cur->first + k))
    {
        deleted += f(it, min(min_cnt_before - deleted, it->second), len + 1LL);
    }

    lli dm = min(m, min_cnt_before - deleted);
    m -= dm;
    ans += dm * len;

    lli d = dm + deleted;
    cur->second -= d;
    if (cur->second == 0LL)
        cnt.erase(cur);
    return d;
}
