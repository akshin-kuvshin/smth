// author: Danila "akshin_" Axyonov

#include <iostream>
#include <iomanip>
#include <vector>
using namespace std;
using lli = long long int;
using plli = pair<lli, lli>;

#define mp(_first, _second) make_pair(_first, _second)
#define pb(_elem)           push_back(_elem)

#define a                   first
#define b                   second

#define sum                 first
#define cnt                 second

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
    vector<plli> p(n);
    for (auto& pi : p) {
        cin >> pi.a >> pi.b;
        --pi.a;
    }

    vector<plli> q(m);
    for (auto pi : p) {
        q[pi.a].sum += pi.b;
        ++q[pi.a].cnt;
    }

    for (auto qi : q)
        cout << fixed << setprecision(20) << (double)qi.sum / (double)qi.cnt << '\n';
    return;
}
