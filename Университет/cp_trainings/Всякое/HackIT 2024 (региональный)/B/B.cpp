// author: Danila "akshin_" Axyonov

#include <iostream>
#include <iomanip>
#include <vector>
using namespace std;
using lli = long long int;
using ld = long double;

#define plli                pair<lli, lli>
#define mp(_first, _second) make_pair(_first, _second)
#define pb(_elem)           push_back(_elem)

const lli SIZE = 123LL;

void solve();

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    solve();
    
    return 0;
}

void solve() {
    lli n,
        m;
    cin >> n >> m;
    vector<ld> p(SIZE);
    p[n] = 1.l;

    ld ans = 0.l;
    lli bet = 1LL;
    bool was_changes;
    do {
        was_changes = false;

        vector<ld> new_p(SIZE);
        for (int i = 0; i < (int)SIZE; ++i) {
            if (i - (int)bet >= 0) {
                new_p[i] += p[i - (int)bet];
                was_changes = true;
            }
            if (i + (int)bet < (int)SIZE) {
                new_p[i] += p[i + (int)bet];
                was_changes = true;
            }
            new_p[i] *= .5l;
        }
        p = new_p;

        for (int i = (int)m; i < (int)SIZE; ++i) {
            ans += p[i];
            p[i] = 0.l;
        }
        ++bet;
    } while (was_changes);

    cout << fixed << setprecision(20) << ans << '\n';
    return;
}
