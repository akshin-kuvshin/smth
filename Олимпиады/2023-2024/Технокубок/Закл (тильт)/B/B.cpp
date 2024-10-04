#include <iostream>
#include <vector>
using namespace std;
typedef long long int lli;

#define plli                        pair<lli, lli>
#define mp(_first, _second)         make_pair(_first, _second)
#define pb(_elem)                   push_back(_elem)

const lli MAX_SIZE = (lli)1e5 + 5LL,
          INF = (lli)1e18 + 1LL;

struct Node {
    lli a;
    lli b;
    lli c;
    lli d;
};

lli N;
Node A[MAX_SIZE];
vector<Node> neg,
             zer,
             pos;
lli ans;

void solve();

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}

void solve() {
    cin >> N;
    for (int i = 0; i < (int)N; ++i)
        cin >> A[i].a;
    for (int i = 0; i < (int)N; ++i)
        cin >> A[i].b;
    for (int i = 0; i < (int)N; ++i)
        cin >> A[i].c;
    for (int i = 0; i < (int)N; ++i)
        cin >> A[i].d;
    
    for (int i = 0; i < (int)N; ++i)
        if (A[i].a < 0LL)
            neg.pb(A[i]);
        else if (A[i].a == 0LL)
            zer.pb(A[i]);
        else // A[i].a > 0LL
            pos.pb(A[i]);
    
    lli m = INF;
    for (Node n : neg)
        m = min(m, ((-n.a) / n.b + 1LL) * n.c);
    for (Node n : pos)
        m = min(m, (n.a / n.b + 1LL) * n.d);

    if (zer.empty()) {
        if ((lli)neg.size() % 2LL == 0LL) {
            cout << "0\n";
            return;
        }
        
        cout << m << '\n';
        return;
    }

    vector<plli> dp(zer.size()); // pos - neg
    dp[0] = mp(zer[0].c, zer[0].d);
    for (int i = 1; i < (int)zer.size(); ++i) {
        dp[i].first = min(dp[i - 1].first + zer[i].c, dp[i - 1].second + zer[i].d);
        dp[i].second = min(dp[i - 1].first + zer[i].d, dp[i - 1].second + zer[i].c);
    }

    if (m == INF)
        ans = dp.back().first;
    else { // m != INF
        if ((lli)neg.size() % 2LL == 0LL)
            ans = min(dp.back().first, m + dp.back().second);
        else // (lli)neg.size() % 2LL == 1LL
            ans = min(dp.back().second, m + dp.back().first);
    }
    cout << ans << '\n';
    return;
}
