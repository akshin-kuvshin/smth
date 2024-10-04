// author: Danila "akshin_" Aksionov
#include <iostream>
#include <iomanip>
using namespace std;
typedef long long int lli;

const lli MAX = 25LL;

lli n,
    a,
    b,
    t[MAX];
char h1, h2,
     sep,
     m1, m2;
double charge = 100.;
bool f = true;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin >> n >> a >> b;
    t[0] = 0LL;
    for (int i = 0; i < (int)n; ++i) {
        cin >> h1 >> h2 >> sep >> m1 >> m2;
        lli hour = 10LL * ((lli)h1 - '0') + (lli)h2 - '0',
            minute = 10LL * ((lli)m1 - '0') + (lli)m2 - (lli)'0';
        
        t[i + 1] = 60LL * hour + minute;
    }
    t[(int)n + 1] = 1440LL - 1LL;

    for (int i = 1; i <= (int)n + 1; ++i) {
        lli dt = t[i] - t[i - 1];
        if (f) {
            charge += (double)dt / (double)b * 100.;
            charge = min(charge, 100.);
            f = false;
        } else {
            charge -= (double)dt / (double)a * 100.;
            charge = max(charge, 0.);
            f = true;
        }
    }

    cout << fixed << setprecision(20) << charge << '\n';
    return 0;
}
