// author: Danila "akshin_" Aksionov

#include <iostream>
#include <iomanip>
#include <algorithm>
using namespace std;
typedef long long int lli;

#define pb(elem) push_back(elem)
#define mp(_first, _second) make_pair(_first, _second)
#define sz(object) (lli)(object).size()
#define all(object) (object).begin(), (object).end()

const lli MAX_SIZE = (lli)1e5;

lli N,
    A[MAX_SIZE + 5LL],
    B[MAX_SIZE + 5LL];
lli K;
double d[MAX_SIZE + 5LL];
double answer;

bool f(double);
double bs();

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin >> N >> K;
    for (int i = 0; i < (int)N; ++i)
        cin >> A[i] >> B[i];
    
    answer = bs();
    cout << fixed << setprecision(20) << answer << '\n';
    return 0;
}

bool f(double x) {
    for (int i = 0; i < (int)N; ++i)
        d[i] = (double)A[i] - x * (double)B[i];
    sort(d, d + N, greater<double>());

    double _sum = 0.;
    for (int i = 0; i < (int)K; ++i)
        _sum += d[i];
    return (_sum >= 0.);
}

double bs() {
    double l = 0.,
           r = 1e6;
    
    for (int _ = 0; _ < 100; ++_) {
        double mid = (l + r) * .5;
        if (f(mid))
            l = mid;
        else
            r = mid;
    }

    return l;
}
