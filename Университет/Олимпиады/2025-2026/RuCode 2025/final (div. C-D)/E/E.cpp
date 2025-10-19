// authors: Danila "akshin_" Axyonov & Stepan Evseev

#include <iostream>
using namespace std;
typedef long long int lli;

#define mp(_first, _second)     make_pair(_first, _second)
#define pb(_elem)               push_back(_elem)

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

    lli k = 1LL;
    for (; k * k <= n; ++k) {
        if (n % k != 0LL)
            continue;
        if ((k - 15LL) % 14LL != 0LL)
            continue;
        lli d = (k - 15LL) / 14LL;
        if (d < 16LL)
            continue;
        cout << d << '\n';
        return;
    }
    for (; k > 0LL; --k) {
        if (n % k != 0LL)
            continue;
        lli m = n / k;
        if ((m - 15LL) % 14LL != 0LL)
            continue;
        lli d = (m - 15LL) / 14LL;
        if (d < 16LL)
            continue;
        cout << d << '\n';
        return;
    }

    cout << "-1\n";
    return;
}

