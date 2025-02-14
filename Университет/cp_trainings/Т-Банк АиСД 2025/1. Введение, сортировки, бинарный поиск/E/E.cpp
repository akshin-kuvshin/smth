// author: Danila "akshin_" Axyonov

#include <iostream>
#include <iomanip>
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
    lli a,
        b,
        c,
        d;
    cin >> a >> b >> c >> d;
    if (a < 0LL) {
        a = -a;
        b = -b;
        c = -c;
        d = -d;
    }

    double l = -1e10,
           r = 1e10;
    for (int _ = 0; _ < 200; ++_) {
        double m = (l + r) * .5;
        if ((double)a * m * m * m + (double)b * m * m + (double)c * m + (double)d < 0.)
            l = m;
        else
            r = m;
    }
    cout << fixed << setprecision(20) << l << '\n';    
    return;
}
