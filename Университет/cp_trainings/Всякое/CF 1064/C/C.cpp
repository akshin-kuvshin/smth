// author: Danila "akshin_" Axyonov

#include <iostream>
#include <vector>
#include <set>
typedef long long int lli;
using namespace std;

struct Node {
    lli val;
    lli l;
    lli r;

    bool operator<(const Node &n) const {
        if (val != n.val)
            return val < n.val;
        return l < n.l;
    }
};

void solve();

int main() {
    int q;
    cin >> q;
    while (q--)
        solve();
    return 0;
}

void solve() {
    lli n;
    cin >> n;
    vector<Node> a(n);
    set<Node> S;
    for (int i = 0; i < (int)n; ++i) {
        lli val;
        cin >> val;
        a[i] = { val, (lli)i, (lli)i };
        S.insert(a[i]);
    }

    lli ans = 0LL;
    for (int _ = 0; _ + 1 < (int)n; ++_) {
        Node cur = *S.begin();
        S.erase(S.begin());

        Node nb_left = a[(cur.l - 1LL + n) % n],
             nb_right = a[(cur.r + 1LL) % n];
        if (nb_left.val < nb_right.val) {
            S.erase(nb_left);

            a[nb_left.l].r = cur.r;

            a[cur.r].l = nb_left.l;
            a[cur.r].val = nb_left.val;
            
            ans += a[cur.r].val;

            S.insert(a[cur.r]);
        } else {
            S.erase(nb_right);

            a[nb_right.r].l = cur.l;

            a[cur.l].r = nb_right.r;
            a[cur.l].val = nb_right.val;

            ans += a[cur.l].val;

            S.insert(a[cur.l]);
        }
    }

    cout << ans << '\n';
}
