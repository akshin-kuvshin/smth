// author: Danila "akshin_" Aksionov

#include <iostream>
#include <iomanip>
using namespace std;
typedef long long int lli;

#define plli                pair<lli, lli>
#define mp(_first, _second) make_pair(_first, _second)
#define pb(_elem)           push_back(_elem)

double a;
lli n;
double root;

void solve();
double _pow(double, lli);
bool f(double);
double bs();

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    solve();
    
    return 0;
}

void solve() {
    cin >> a >> n;
    root = bs();
    cout << fixed << setprecision(20) << root << '\n';
    return;
}

double _pow(double base, lli ptr) {
    if (ptr == 0LL)
        return 1.0;
    return base * _pow(base, ptr - 1LL);
}

bool f(double x) {
    return _pow(x, n) < a;
}

double bs() {
    double l = 0.0,
           r = 1001.0;
    
    int _ = 100;
    while (_--) {
        double mid = (l + r) * 0.5;
        if (f(mid))
            l = mid;
        else
            r = mid;
    }

    return l;
}
