// author: Danila "akshin_" Axyonov

#include <iostream>
using namespace std;
typedef long long int lli;

#define mp(arg1, arg2)      make_pair(arg1, arg2)
#define pb(arg)             push_back(arg)

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
    if (n < 8LL or n == 9LL) {
        cout << "-1\n";
        return;
    }
    
    lli ans1;
    if (n < 24LL) {
        lli m1 = n / 2LL - 4LL, // == (n - 8LL) / 2LL
            m2 = n % 2LL; // == (n - 8LL) % 2LL
        ans1 = 7LL + 3LL * (m1 + m2);
    } else { // n >= 24LL
        lli m1 = n / 8LL,
            m2 = n % 8LL;
        lli a = m1 * (m1 - 1LL) / 2LL,
            b = (m1 + 1LL) * m1 / 2LL;
        ans1 = 7LL + (8LL - m2) * a + m2 * b;
    }
    
    lli ans2 = (n - 7LL) * (n - 8LL) / 2LL + 7LL;

    cout << ans1 << ' ' << ans2 << '\n';
    return;
}

