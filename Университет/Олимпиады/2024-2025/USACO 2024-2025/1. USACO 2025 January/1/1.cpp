// author: Danila "akshin_" Axyonov

#include <iostream>
#include <vector>
#include <algorithm>
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
    vector<lli> a(n),
                b(n);
    for (int i = 0; i < (int)n; ++i) {
        cin >> a[i];
        --a[i];
    }
    for (int i = 0; i < (int)n; ++i) {
        cin >> b[i];
        --b[i];
    }
    
    vector<vector<lli>> m(n);
    for (int i = 0; i < (int)n; ++i)
        m[a[i]].pb((lli)i);
    vector<vector<lli>> pref_sum(n),
                        suf_sum(n);
    for (int i = 0; i < (int)n; ++i) {
        if (m[i].empty())
            continue;

        pref_sum[i].resize(m[i].size());
        pref_sum[i].front() = m[i].front() + 1LL;
        for (int j = 1; j < (int)m[i].size(); ++j)
            pref_sum[i][j] = pref_sum[i][j - 1] + m[i][j] + 1LL;

        suf_sum[i].resize(m[i].size());
        suf_sum[i].back() = n - m[i].back();
        for (int j = (int)m[i].size() - 2; j >= 0; --j)
            suf_sum[i][j] = suf_sum[i][j + 1] + (n - m[i][j]);
    }

    lli ans = 0LL;
    for (lli i = 0LL; i < n; ++i) {
        vector<lli>& cur_m = m[b[i]];
        vector<lli>& cur_pref_sum = pref_sum[b[i]];
        vector<lli>& cur_suf_sum = suf_sum[b[i]];
        if (cur_m.empty())
            continue;

        // check for cur
        if (a[i] == b[i]) {
            ans += min(i + 1LL, n - i);
            ans += i * (i + 1LL) / 2LL;
            ans += (n - i - 1LL) * (n - i) / 2LL;
        }
        
        // check for left and right
        lli l = (lli)(lower_bound(cur_m.begin(), cur_m.end(), i) - cur_m.begin() - 1);
        lli r = (lli)(upper_bound(cur_m.begin(), cur_m.end(), i) - cur_m.begin());

        if (n % 2LL == 0LL) {
            if (i < n / 2LL) {
                if (l != -1LL)
                    ans += cur_pref_sum[l];
                if (r != (lli)cur_m.size()) {
                    lli j = (lli)(upper_bound(cur_m.begin(), cur_m.end(), n - i - 1LL) - cur_m.begin());
                    ans += (i + 1LL) * (j - r);
                    if (j != (lli)cur_m.size())
                        ans += cur_suf_sum[j];
                }
            } else { // i >= n / 2LL
                if (r != (lli)cur_m.size())
                    ans += cur_suf_sum[r];
                if (l != -1LL) {
                    lli j = (lli)(lower_bound(cur_m.begin(), cur_m.end(), n - i - 1LL) - cur_m.begin() - 1);
                    ans += (n - i) * (l - j);
                    if (j != -1LL)
                        ans += cur_pref_sum[j];
                }
            }
        } else { // n % 2LL == 1LL
            if (i == n / 2LL) {
                if (l != -1LL)
                    ans += cur_pref_sum[l];
                if (r != (lli)cur_m.size())
                    ans += cur_suf_sum[r];
            } else if (i < n / 2LL) {
                if (l != -1LL)
                    ans += cur_pref_sum[l];
                if (r != (lli)cur_m.size()) {
                    lli j = (lli)(upper_bound(cur_m.begin(), cur_m.end(), n - i - 1LL) - cur_m.begin());
                    ans += (i + 1LL) * (j - r);
                    if (j != (lli)cur_m.size())
                        ans += cur_suf_sum[j];
                }
            } else { // i > n / 2LL
                if (r != (lli)cur_m.size())
                    ans += cur_suf_sum[r];
                if (l != -1LL) {
                    lli j = (lli)(lower_bound(cur_m.begin(), cur_m.end(), n - i - 1LL) - cur_m.begin() - 1);
                    ans += (n - i) * (l - j);
                    if (j != -1LL)
                        ans += cur_pref_sum[j];
                }
            }
        }
    }
    
    cout << ans << '\n';
    return;
}
