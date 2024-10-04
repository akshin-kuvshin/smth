#include <iostream>
#include <iomanip>
using namespace std;
typedef long long int lli;

const size_t MAX_SIZE = 100000LL;

size_t N;
lli x[MAX_SIZE + 5ULL],
    v[MAX_SIZE + 5ULL];
double answer;

bool f(double);
double bs();

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N;
    for (size_t i = 0ULL; i < N; ++i)
        cin >> x[i] >> v[i];
    answer = bs();
    cout << setprecision(20) << answer << '\n';
    
    return 0;
}

bool f(double T) {
    double l,
           r;
    
    l = (double)x[0] - T * (double)v[0];
    r = (double)x[0] + T * (double)v[0];
    for (size_t i = 1ULL; i < N; ++i) {
        l = max(l, (double)x[i] - T * (double)v[i]);
        r = min(r, (double)x[i] + T * (double)v[i]);
    }

    return (l <= r);
}

double bs() {
    if (N == 1ULL)
        return 0.0;

    double l = 0.0,
           r = 5e18;
    
    for (size_t i = 0ULL; i < 100ULL; ++i) {
        double mid = (l + r) * .5;

        if (f(mid))
            r = mid;
        else
            l = mid;
    }

    return r;
}

// x = [xi - T * vi; xi + T * vi]
