// author: Danila "akshin_" Aksionov

#include <iostream>
using namespace std;
typedef long long int lli;

#define pb(elem) push_back(elem)
#define mp(_first, _second) make_pair(_first, _second)
#define sz(object) (lli)(object).size()
#define all(object) (object).begin(), (object).end()

#define num first
#define index second

const lli MAX_SIZE = (lli)1e5;

lli N,
    A[MAX_SIZE + 5LL],
    D;
lli cur_l,
    cur_r;
double ps[MAX_SIZE + 5LL]; // prefix sums: ps[i] = sum of A[] in [0..i)
pair<double, lli> pmps[MAX_SIZE + 5LL]; // prefix minimums of prefix sums: pmps[i].num = min of ps[] in [0..i)

void bs();
bool f(lli);

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin >> N >> D;
    for (int i = 0; i < (int)N; ++i)
        cin >> A[i];
    
    bs();
    
    cout << ++cur_l << ' ' << cur_r << '\n';
    return 0;
}

bool f(double x) {
    ps[0] = 0.;
    for (int i = 0; i < (int)N; ++i)
        ps[i + 1] = ps[i] + (double)A[i] - x;
    
    pmps[0] = mp(0., 0LL);
    for (int i = 1; i < (int)N; ++i)
        if (ps[i] < pmps[i - 1].num)
            pmps[i] = mp(ps[i], i);
        else
            pmps[i] = pmps[i - 1];
    
    for (int i = (int)D; i <= (int)N; ++i)
        if (pmps[i - (int)D].num <= ps[i]) {
            cur_l = pmps[i - (int)D].index;
            cur_r = i;
            return true;
        }
    return false;
}

void bs() {
    double l = -1.,
           r = 101.;
    
    for (int _ = 0; _ < 100; ++_) {
        double mid = (l + r) * .5;

        if (f(mid))
            l = mid;
        else
            r = mid;
    }

    // cout << "maxmid = " << l << '\n';
    return;
}
