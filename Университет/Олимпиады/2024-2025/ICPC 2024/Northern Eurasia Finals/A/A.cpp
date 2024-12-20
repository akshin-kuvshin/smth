// author: Danila "akshin_" Axyonov

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long int lli;
typedef pair<lli, lli> plli;

void solve();

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}

void solve() {
    lli N;
    cin >> N;
    vector<lli> res(N);
    for (int i = 0; i < (int)N; ++i)
        cin >> res[i];

    vector<lli> P(N);
    generate(P.begin(), P.end(), []() { static lli i = 1LL; return i++; });
    vector<plli> ops;
    for (int __i = 0; __i < (int)N; ++__i) {
        lli car = res[__i];
        lli i = 0LL;
        while (P[i] != car)
            ++i;
        while (i != N - 1LL) {
            swap(P[i], P[i + 1LL]);
            ops.push_back(make_pair(P[i], P[i + 1LL]));
            ++i;
        }
        while (i != __i) {
            swap(P[i], P[i - 1LL]);
            ops.push_back(make_pair(P[i - 1LL], P[i]));
            --i;
        }
    }

    cout << ops.size() << '\n';
    for (plli p : ops)
        cout << p.first << ' ' << p.second << '\n';

    return;
}
