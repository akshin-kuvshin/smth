// author: Danila "akshin_" Axyonov

#include <iostream>
#include <iomanip>
using namespace std;
typedef long long int lli;

#define plli                pair<lli, lli>
#define mp(_first, _second) make_pair(_first, _second)
#define pb(_elem)           push_back(_elem)

const lli MAX_SIZE = (lli)1e3 + 5LL;

struct City {
    lli x;
    lli y;
    lli k;
};

lli N;
City A[MAX_SIZE];
lli S;
double ans;

void solve();
double bs();
bool f(double);

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    solve();
    
    return 0;
}

void solve() {
    cin >> N >> S;
    for (int i = 0; i < (int)N; ++i)
        cin >> A[i].x >> A[i].y >> A[i].k;
    
    ans = bs();
    if (f(ans))
        cout << fixed << setprecision(20) << ans;
    else
        cout << -1;
    cout << '\n';
    
    return;
}

double bs() {
    double l = .0,      // no
           r = 1e6;     // yes
    for (int _ = 0; _ < 100; ++_) {
        double mid = (l + r) * .5;
        if (f(mid))
            r = mid;
        else
            l = mid;
    }
    return r;
}

bool f(double r) {
    lli _S = 0LL;
    for (int i = 0; i < (int)N; ++i)
        if ((double)(A[i].x * A[i].x + A[i].y * A[i].y) <= r * r)
            _S += A[i].k;
    return (S + _S >= (lli)1e6);
}
