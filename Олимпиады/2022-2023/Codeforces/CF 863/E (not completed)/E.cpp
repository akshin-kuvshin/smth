#include <iostream>
using namespace std;
typedef long long int lli;

const lli MAX_DIGIT_AMOUNT = 12LL;

lli Q;
lli _k,
    k;
// A[i] = "сколько чисел от 1 до 10^i содержат цифру 4".
lli A[MAX_DIGIT_AMOUNT + 5LL] = {0LL, 1LL},
    pow_of_10[MAX_DIGIT_AMOUNT + 5LL] = {1LL, 10LL, 100LL, 1000LL, 10000LL, 100000LL, 1000000LL, 10000000LL, 100000000LL, 1000000000LL, 10000000000LL, 100000000000LL, 1000000000000LL};
lli ans;

void solve();
void fill_A();

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    fill_A();

    cin >> Q;
    while (Q--)
        solve();
    
    return 0;
}

void solve() {
    cin >> k;
    _k = k;
    ans = 0LL;

    lli ind = 0LL;
    while (pow_of_10[ind] < _k) ++ind;

    while (_k) {
        lli d = _k / pow_of_10[ind];

        if (d < 4LL)
            ans += A[ind] * d;
        else if (d == 4LL) {
            ans += A[ind] * 3LL + _k % pow_of_10[ind];
            break;
        } else // d > 4LL
            ans += A[ind] * (d - 1LL) + pow_of_10[ind];
        
        _k %= pow_of_10[ind];
        --ind;
    }

    cout << ans << '\n';
    return;
}

void fill_A() {
    for (int i = 2; i <= (int)MAX_DIGIT_AMOUNT; ++i)
        A[i] = 10 * A[i - 1] + (pow_of_10[i - 1] - A[i - 1]);
    return;
}
