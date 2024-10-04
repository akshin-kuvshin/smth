// author: Danila "akshin_" Aksionov

#include <iostream>
using namespace std;
typedef long long int lli;

#define plli                pair<lli, lli>
#define mp(_first, _second) make_pair(_first, _second)
#define pb(_elem)           push_back(_elem)

lli A,
    B,
    d;

void solve();
lli f(lli);

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    solve();
    
    return 0;
}

void solve() {
    cin >> A >> B >> d;

    if ((A + B) % 2LL == 0LL) {
        lli x = (A + B) >> 1;
        lli dx = min(f(x), d - f(x));
        cout << x << ' ' <<  dx << '\n';
    } else { // (A + B) % 2LL == 1LL
        lli x1 = (A + B) >> 1;
        lli x2 = x1 + 1LL;

        lli dx1 = min(f(x1), d - f(x1)),
            dx2 = min(f(x2), d - f(x2));
        
        if (dx1 < dx2)
            cout << x1 << ' ' << dx1 << '\n';
        else // dx1 > dx2, because dx1 can't be equal to dx2, because d is even number.
            cout << x2 << ' ' << dx2 << '\n';
    }
    
    return;
}

lli f(lli n) {
    if (n >= 0LL)
        return n % d;
    return (n % d + d) % d;
}
