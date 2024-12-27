// author: Danila "akshin_" Axyonov
// Буду честен: прежде чем получить вердикт "Submitted", я подглядел в решение другого человека.

#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;
typedef long long int lli;

#define plli                pair<lli, lli>
#define mp(_first, _second) make_pair(_first, _second)
#define pb(_elem)           push_back(_elem)

const lli INF = (lli)1e18 + 1LL;

void solve();

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    solve();
    
    return 0;
}

void solve() {
    size_t n;
    cin >> n;
    vector<plli> north,
                 east;
    vector<lli> xs;
    unordered_map<lli, lli> ans;
    for (size_t _ = 0ULL; _ < n; ++_) {
        char dir;
        lli x, y;
        cin >> dir >> x >> y;
        if (dir == 'N') north.pb(mp(x, y));
        else /* dir == 'E' */ east.pb(mp(x, y));
        xs.pb(x);
        ans[x] = -1LL;
    }
    
    sort(north.begin(), north.end());
    sort(east.begin(), east.end(), [](const plli &p1, const plli &p2) {
        return p1.second < p2.second;
    });

    for (auto [xn, yn] : north) {
        for (auto [xe, ye] : east) {
            if (ans[xe] != -1LL) continue;
            if (xn < xe or yn > ye) continue;
            // now xn > xe, yn < ye
            lli dn = ye - yn,
                de = xn - xe;
            if (dn < de)
                ans[xe] = de;
            else if (dn > de) {
                ans[xn] = dn;
                break;
            }
        }
    }
    
    for (auto x : xs) {
        if (ans[x] == -1LL)
            cout << "Infinity\n";
        else // ans[x] != -1LL
            cout << ans[x] << '\n';
    }
    return;
}
