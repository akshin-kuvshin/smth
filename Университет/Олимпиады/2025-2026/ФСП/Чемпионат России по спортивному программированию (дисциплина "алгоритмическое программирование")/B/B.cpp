// author: Danila "akshin_" Axyonov

#include <iostream>
#include <vector>
using namespace std;
typedef long long int lli;
typedef pair<lli, lli> plli;
#define x first
#define y second

const lli INF = (lli)1e18 + 1LL;

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
    vector<pair<plli, lli>> a(n);
    lli m = -INF;
    for (pair<plli, lli>& p : a) {
        cin >> p.first.x >> p.first.y;
        p.second = p.first.x - p.first.y;
        m = max(m, p.second);
    }

    vector<lli> ans;
    for (int i = 0; i < (int)n; ++i)
        if (a[i].second == m)
            ans.push_back((lli)(i + 1));

    cout << ans.size() << '\n';
    for (lli ind : ans)
        cout << ind << '\n';
    return;
}
