#include <iostream>
#include <string>
using namespace std;
typedef long long int lli;

const lli MAX_FIB_INDEX = 44LL;

lli Q;
lli N,
    x,
    y;
lli fib[MAX_FIB_INDEX + 5LL] = {1LL, 1LL};
string ans[2] = {"NO\n", "YES\n"};

void solve();
lli get_fib(lli);
bool is_good_point(lli, lli, lli);

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    get_fib(MAX_FIB_INDEX);

    cin >> Q;
    while (Q--)
        solve();
    
    return 0;
}

void solve() {
    cin >> N >> x >> y;
    cout << ans[is_good_point(N, x, y)];
    return;
}

lli get_fib(lli fib_index) {
    if (fib[fib_index])
        return fib[fib_index];
    fib[fib_index] = get_fib(fib_index - 2LL) + get_fib(fib_index - 1LL);
    return fib[fib_index];
}

bool is_good_point(lli order, lli _x, lli _y) {
    if (order < 2LL)
        return true;
    if (fib[order - 1LL] < _y and _y <= fib[order])
        return false;
    if (_y <= fib[order - 1LL])
        return is_good_point(order - 1LL, _y, _x);
    // else // fib[order] < _y
    return is_good_point(order - 1LL, _y - fib[order], _x);
}
