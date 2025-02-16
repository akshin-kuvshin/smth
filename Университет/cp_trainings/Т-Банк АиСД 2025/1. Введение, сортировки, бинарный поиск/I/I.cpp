// author: Danila "akshin_" Axyonov

#include <iostream>
#include <vector>
#include <set>
using namespace std;
using lli = long long int;
using plli = pair<lli, lli>;

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
    lli n;
    cin >> n;
    vector<lli> a(n);

    set<plli> zero_segs;
    zero_segs.insert(mp(0LL, n - 1LL));
    lli from_ones = 0LL;

    cout << "1 "; // (lli)zero_segs.size() + from_ones == 1LL
    for (lli q = 0LL; q < n; ++q) {
        lli ind;
        cin >> ind;
        --ind;

        if (q == n - 1LL) {
            cout << "1\n";
            break; // also we could write "continue;"
        }

        plli p = *(--zero_segs.upper_bound(mp(ind, INF)));
        zero_segs.erase(p);
        plli p1 = mp(p.first, ind - 1LL),
             p2 = mp(ind + 1LL, p.second);
        if (p1.first <= p1.second)
            zero_segs.insert(p1);
        if (p2.first <= p2.second)
            zero_segs.insert(p2);

        if (ind == 0LL) {
            from_ones += a[ind + 1LL] + 1LL;
            a[ind] = 1LL;
        } else if (ind == n - 1LL) {
            lli i = ind,
                prev_len = 0LL;
            while (a[--i])
                ++prev_len;
            from_ones -= max(prev_len - 1LL, 0LL);
            a[i + 1LL] = -1LL;
        } else { // 0LL < ind < n - 1LL
            if (a[ind + 1LL] == -1LL) {
                lli i = ind,
                    prev_len = 0LL;
                while (a[--i])
                    ++prev_len;
                from_ones -= max(prev_len - 1LL, 0LL);
                a[i + 1LL] = -1LL;
            } else {
                from_ones += a[ind - 1LL] + a[ind + 1LL];
                a[ind] = 1LL;
            }
        }
        
        cout << (lli)zero_segs.size() + from_ones << ' ';
    }
    
    return;
}
