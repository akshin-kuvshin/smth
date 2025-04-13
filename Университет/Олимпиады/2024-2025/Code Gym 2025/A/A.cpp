// author: Danila "akshin_" Axyonov

#include <iostream>
#include <iomanip>
#include <vector>
#include <cmath>
using namespace std;
using lli = long long int;

#define plli                pair<lli, lli>
#define mp(_first, _second) make_pair(_first, _second)
#define pb(_elem)           push_back(_elem)

const double eps = 1e-6;

void solve();

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    solve();
    
    return 0;
}

void solve() {
    lli w;
    cin >> w;
    w -= 20LL;

    bool flag = false;
    for (lli k125 = 0LL; k125 <= 80LL and not flag; ++k125)
        for (lli k25 = 0LL; k25 <= 40LL and not flag; ++k25)
            for (lli k5 = 0LL; k5 <= 20LL and not flag; ++k5)
                for (lli k10 = 0LL; k10 <= 10LL and not flag; ++k10)
                    for (lli k20 = 0LL; k20 <= 5LL and not flag; ++k20)
                        if (abs((double)k125 * 1.25 + (double)k25 * 2.5 + (double)k5 * 5. + (double)k10 * 10. + (double)k20 * 20. - (double)w * .5) < eps)
                            flag = true;

    if (flag)
        cout << fixed << setprecision(2) << (double)w * .5 << '\n';
    else // not flag
        cout << "-1\n";
    return;
}
