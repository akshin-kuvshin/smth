#include <iostream>
#include <string>
using namespace std;
typedef long long int lli;

lli Q;
lli N,
    x1,
    y1,
    x2,
    y2;
lli layer1,
    layer2;
lli ans;

void solve();

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> Q;
    while (Q--)
        solve();
    
    return 0;
}

void solve() {
    cin >> N >> x1 >> y1 >> x2 >> y2;
    --x1, --x2, --y1, --y2;
    if (x1 >= (N / 2LL))
        x1 = N - x1 - 1LL;
    if (x2 >= (N / 2LL))
        x2 = N - x2 - 1LL;
    if (y1 >= (N / 2LL))
        y1 = N - y1 - 1LL;
    if (y2 >= (N / 2LL))
        y2 = N - y2 - 1LL;

    layer1 = min(x1 + 1LL, y1 + 1LL);
    layer2 = min(x2 + 1LL, y2 + 1LL);

    ans = abs(layer1 - layer2);
    cout << ans << '\n';

    return;
}
