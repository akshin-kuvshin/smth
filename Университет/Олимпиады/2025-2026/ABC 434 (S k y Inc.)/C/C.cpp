// author: Danila "akshin_" Axyonov

#include <iostream>
#include <vector>
using namespace std;
using lli = long long int;
using plli = pair<lli, lli>;

#define mp(_first, _second) make_pair(_first, _second)
#define pb(_elem)           push_back(_elem)

struct Node {
    lli t;
    lli l;
    lli u;
};

void solve();

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    lli q;
    cin >> q;
    while (q--)
        solve();

    return 0;
}

void solve() {
    lli n,
        h;
    cin >> n >> h;
    vector<Node> a(n);
    for (auto& ai : a)
        cin >> ai.t >> ai.l >> ai.u;

    lli min_ = h,
        max_ = h,
        t_ = 0LL;
    for (auto [t, l, u] : a) {
        min_ = min_ - (t - t_);
        max_ = max_ + (t - t_);

        min_ = max(min_, l);
        max_ = min(max_, u);
        if (min_ > max_) {
            cout << "No\n";
            return;
        }

        t_ = t;
    }
    cout << "Yes\n";
    return;
}
