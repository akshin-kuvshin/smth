#include <iostream>
#include <iomanip>
using namespace std;
typedef long long int lli;

const lli MAX_SIZE = 10000LL;

lli N,
    A[MAX_SIZE + 5LL],
    K;
double answer;

bool f(double);
double bs();

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N >> K;
    for (int i = 0; i < (int)N; ++i)
        cin >> A[i];
    
    answer = bs();
    cout << fixed << setprecision(7) << answer << '\n';    
    return 0;
}

bool f(double x) {
    lli counter = 0LL;
    for (int i = 0; i < (int)N; ++i)
        counter += (lli)((double)A[i] / x);
    return (counter >= K);
}

double bs() {
    double l = 0.0,
           r = 1e9;
    
    for (int i = 0; i < 100; ++i) {
        double m = (l + r) * 0.5;
        
        if (f(m))
            l = m;
        else
            r = m;
    }

    return l;
}
