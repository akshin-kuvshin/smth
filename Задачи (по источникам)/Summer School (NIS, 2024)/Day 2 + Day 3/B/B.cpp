// author: Danila "akshin_" Axyonov

#include <iostream>
using namespace std;
typedef long long int lli;

#define plli                pair<lli, lli>
#define mp(_first, _second) make_pair(_first, _second)
#define pb(_elem)           push_back(_elem)

const lli INF = (lli)1e18 + 1LL;

lli n;
lli dl = INF,
    dr = INF;
lli m;
lli ans;

void solve();
lli sum_of_digits(lli);
bool is_prime(lli);

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    solve();
    
    return 0;
}

void solve() {
    cin >> n;
    
    m = n;
    while (m > 0LL) {
        if (is_prime(sum_of_digits(m))) {
            dl = abs(n - m);
            break;
        }
        --m;
    }

    m = n;
    while (true) {
        if (is_prime(sum_of_digits(m))) {
            dr = abs(n - m);
            break;
        }
        ++m;
    }

    ans = min(dl, dr);
    cout << ans << '\n';
    return;
}

lli sum_of_digits(lli num) {
    lli res = 0LL;
    while (num) {
        res += num % 10LL;
        num /= 10LL;
    }
    return res;
}

bool is_prime(lli num) {
    if (num == 1LL)
        return false;
    for (lli d = 2LL; d * d <= num; ++d)
        if (num % d == 0LL)
            return false;
    return true;
}
