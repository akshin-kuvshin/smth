// author: Danila "akshin_" Axyonov

#include <iostream>
#include <iomanip>
#include <vector>
using namespace std;
using lli = long long int;

#define plli                pair<lli, lli>
#define mp(_first, _second) make_pair(_first, _second)
#define pb(_elem)           push_back(_elem)

const double INF = 1e6,
             eps = 1e-6;

double bs(lli n, const vector<lli>& a, lli m, const vector<lli>& b);
bool f(double t, lli n, const vector<lli>& a, lli m, const vector<lli>& b);
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
    vector<lli> a(n);
    for (int i = 0; i < (int)n; ++i)
        cin >> a[i];
    lli m;
    cin >> m;
    vector<lli> b(m);
    for (int i = 0; i < (int)m; ++i)
        cin >> b[i];
    
    double ans = bs(n, a, m, b);
    if (INF - ans > eps)
        cout << fixed << setprecision(20) << ans << '\n';
    else // INF - ans < eps   ->   no answer
        cout << "-1\n";
    
    return;
}

double bs(lli n, const vector<lli>& a, lli m, const vector<lli>& b) {
    double l = -1.,
           r = INF;
    for (int _ = 0; _ < 100; ++_) {
        double mid = (l + r) * .5;
        if (f(mid, n, a, m, b))
            r = mid;
        else // not f(...)
            l = mid;
    }
    return r;
}

bool f(double x, lli n, const vector<lli>& a, lli m, const vector<lli>& b) {
    int ai = 0,
        bi = 0;
    double cur = 0.;
    for (; ai < (int)n and bi < (int)m;) {
        if (a[ai] < b[bi] or cur + 1. * b[bi] / a[ai] > x) {
            ++ai;
            cur = 0.;
            continue;
        }
        cur += 1. * b[bi] / a[ai];
        ++bi;
    }
    return (bi == (int)m);
}
