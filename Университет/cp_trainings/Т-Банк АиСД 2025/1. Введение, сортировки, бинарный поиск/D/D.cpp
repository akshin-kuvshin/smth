// author: Danila "akshin_" Axyonov

#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;
using lli = long long int;

#define plli                pair<lli, lli>
#define mp(_first, _second) make_pair(_first, _second)
#define pb(_elem)           push_back(_elem)

void solve();

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    solve();
    
    return 0;
}

void solve() {
    double C;
    cin >> C;

    double l = 0.,
           r = 1e5;
    for (int _ = 0; _ < 100; ++_) {
        double m = (l + r) * .5;
        if (m * m + sqrt(m + 1.) < C)
            l = m;
        else
            r = m;
    }
    cout << fixed << setprecision(20) << l << '\n';
    return;
}
