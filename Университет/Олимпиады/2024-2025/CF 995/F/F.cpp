// author: Danila "akshin_" Axyonov

#include <iostream>
#include <vector>
using namespace std;
typedef long long int lli;

#define plli                pair<lli, lli>
#define mp(_first, _second) make_pair(_first, _second)
#define pb(_elem)           push_back(_elem)

void solve();
void glue(vector<plli>&);
lli count(const vector<plli>&);

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
        m,
        q;
    cin >> n >> m >> q;
    vector<plli> X;

    // first operation
    {
        lli pos;
        cin >> pos;
        if (pos == m) {
            X.pb(mp(1LL, 1LL));
            X.pb(mp(n, n));
            glue(X);
        } else { // pos != m
            if (pos < m)
                X.pb(mp(max(m - 1LL, 1LL), m));
            else // m < pos
                X.pb(mp(m, min(m + 1LL, n)));
        }
        cout << count(X) << ' ';
    }

    for (int _ = 1; _ < (int)q; ++_) {
        lli pos;
        cin >> pos;

        bool isin = false;
        for (auto &p : X) {
            if (pos < p.first)
                --p.first;
            else if (p.second < pos)
                ++p.second;
            else // p.first <= pos <= p.second
                isin = true;
        }
        glue(X);

        if (isin) {
            X.insert(X.begin(), mp(1LL, 1LL));
            X.pb(mp(n, n));
            glue(X);
        }
        cout << count(X) << ' ';
    }
    cout << '\n';
    return;
}

bool isin(const vector<plli> &X, lli pos) {
    for (auto [l, r] : X)
        if (l <= pos and pos <= r)
            return true;
    return false;
}

void glue(vector<plli> &X) {
    int len = (int)X.size();
    for (int i = len - 2; i >= 0; --i)
        if (X[i].second + 1LL >= X[i + 1].first) {
            X[i].second = X[i + 1].second;
            X.erase(X.begin() + i + 1);
        }
    return;
}

lli count(const vector<plli> &X) {
    lli res = 0LL;
    for (auto [l, r] : X)
        res += r - l + 1LL;
    return res;
}
