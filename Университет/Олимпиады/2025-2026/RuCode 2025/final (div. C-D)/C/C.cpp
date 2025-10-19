// authors: Danila "akshin_" Axyonov & Stepan Evseev

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long int lli;

#define mp(_first, _second)     make_pair(_first, _second)
#define pb(_elem)               push_back(_elem)

void solve();
lli digits_sum(lli num);

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    lli Q;
    cin >> Q;
    while (Q--)
        solve();

    return 0;
}

void solve() {
    lli n,
        k;
    cin >> n >> k;

    vector<lli> ans;

    if (k == 0LL)
        ans.pb(n);
    else if (k == 1LL)
        for (lli S = 1LL; S <= 180LL; ++S) {
            lli x = n - S;
            if (x > 0LL and digits_sum(x) == S)
                ans.pb(x);
        }
    else if (k == 2LL)
        for (lli S = 1LL; S <= 180LL; ++S)
            for (lli SS = 1LL; SS <= 18LL; ++SS) {
                if (digits_sum(S) != SS)
                    continue;
                lli x = n - S - SS;
                if (x > 0LL and digits_sum(x) == S)
                    ans.pb(x);
            }
    else // k >= 3LL
        for (lli S = 1LL; S <= 180LL; ++S)
            for (lli SS = 1LL; SS <= 18LL; ++SS) {
                if (digits_sum(S) != SS)
                    continue;
                for (lli SSS = 1LL; SSS <= 9LL; ++SSS) {
                    if (digits_sum(SS) != SSS)
                        continue;
                    lli x = n - S - SS - SSS * (k - 2LL);
                    if (x > 0LL and digits_sum(x) == S)
                        ans.pb(x);
                }
            }

    sort(ans.begin(), ans.end());

    cout << ans.size() << '\n';
    for (lli x : ans)
        cout << x << ' ';
    cout << '\n';
    return;
}

lli digits_sum(lli num) {
    lli res = 0LL;
    while (num) {
        res += num % 10LL;
        num /= 10LL;
    }
    return res;
}

