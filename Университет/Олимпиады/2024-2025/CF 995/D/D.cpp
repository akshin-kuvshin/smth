// author: Danila "akshin_" Axyonov

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long int lli;

#define plli                pair<lli, lli>
#define mp(_first, _second) make_pair(_first, _second)
#define pb(_elem)           push_back(_elem)

void solve();
lli bs(const vector<lli>&, lli, lli, lli, lli);

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
        x,
        y;
    cin >> n >> x >> y;
    vector<lli> a(n);
    for (int i = 0; i < (int)n; ++i)
        cin >> a[i];
    sort(a.begin(), a.end());

    lli a_sum = 0LL;
    for (int i = 0; i < (int)n; ++i)
        a_sum += a[i];

    lli ans = 0LL;
    for (int i = 0; i < (int)n; ++i) {
        lli cur_sum = a_sum - a[i];

        lli _min = cur_sum - y,
            _max = cur_sum - x;
        ans += bs(a, n, (lli)(i + 1), _min, _max);
    }

    cout << ans << '\n';
    return;
}

lli bs(const vector<lli> &a, lli n, lli start, lli _min, lli _max) {
    lli l,
        r;
    
    l = start - 1LL,
    r = n;
    lli l_res;
    while (l + 1LL < r) {
        lli m = (l + r) >> 1;
        if (a[m] < _min)
            l = m;
        else // _min <= a[m]
            r = m;
    }
    l_res = l + 1LL;

    l = start - 1LL,
    r = n;
    lli r_res;
    while (l + 1LL < r) {
        lli m = (l + r) >> 1;
        if (_max < a[m])
            r = m;
        else // a[m] <= _max
            l = m;
    }
    r_res = r - 1LL;

    return max(r_res - l_res + 1LL, 0LL);
}
