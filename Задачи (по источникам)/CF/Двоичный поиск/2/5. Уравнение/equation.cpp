#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

double c,
       answer;

bool f(double);
double bs();

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> c;
    answer = bs();
    cout << fixed << setprecision(7) << answer << '\n';    
    return 0;
}

bool f(double x) {
    return (x * x + sqrt(x) <= c);
}

double bs() {
    double l = .0,
           r = c;
    
    for (int i = 0; i < 100; ++i) {
        double m = (l + r) * .5;

        if (f(m))
            l = m;
        else
            r = m;
    }

    return l;
}
