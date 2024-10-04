// author: Danila "akshin_" Axyonov

#include <iostream>
#include <set>
using namespace std;
typedef long long int lli;

#define plli                pair<lli, lli>
#define mp(_first, _second) make_pair(_first, _second)
#define pb(_elem)           push_back(_elem)

lli N;
lli W,
    p,
    q;
set<plli> S;
bool cross;

void solve();

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    solve();
    
    return 0;
}

void solve() {
    cin >> N >> W;

    cin >> p >> q;
    if (p > q) swap(p, q);
    S.insert(mp(p, q));

    for (int _ = 1; _ < (int)W; ++_) {
        cin >> p >> q;
        if (cross) continue;

        if (p > q) swap(p, q);

        if (p + 1LL == q or (p == 1LL and q == N)) {
            S.insert(mp(p, q));
            continue;
        }

        if (p == 1LL) {
            auto it = S.lower_bound(mp(p + 1LL, q + 1LL));
            if (it != S.end()) {
                lli a = it->first,
                    b = it->second;
                if (1LL < a and a < q and q < b and b <= N)
                    cross = true;
            }
        } else { // p > 1LL
            auto it = S.lower_bound(mp(1LL, p + 1LL));
            if (it != S.end()) {
                lli a = it->first,
                    b = it->second;
                if (1LL <= a and a < p and p < b and b < q)
                    cross = true;
            }

            it = S.lower_bound(mp(p + 1LL, q + 1LL));
            if (it != S.end()) {
                lli a = it->first,
                    b = it->second;
                if (p < a and a < q and q < b and b <= N)
                    cross = true;
            }
        }

        S.insert(mp(p, q));
    }
    
    if (not cross) cout << "Safe\n";
    else cout << "Unsafe\n";

    return;
}
