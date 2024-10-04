#include <iostream>
using namespace std;
typedef long long int lli;

#define plli                        pair<lli, lli>
#define mp(_first, _second)         make_pair(_first, _second)
#define pb(_elem)                   push_back(_elem)

lli A,
    B,
    N,
    M;
lli k,
    l;
lli x,
    y;

void solve();

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}

void solve() {
    cin >> A >> B >> N >> M;

    k = 2LL * A - B;
    l = 2LL * N - M;

    if (l == 0LL) {
        cout << N << " 0\n";
        return;
    }
    if (k == 0LL) {
        cout << "-1\n";
        return;
    }
    if (l % k != 0LL) {
        cout << "-1\n";
        return;
    }

    y = l / k;
    x = N - A * y;

    if (x >= 0LL and y >= 0LL)
        cout << x << ' ' << y << '\n';
    else
        cout << "-1\n";

    return;
}
