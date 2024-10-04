#include <iostream>
using namespace std;
typedef long long int lli;

lli w,
    h,
    N;

bool f(lli);
lli bs();

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> w >> h >> N;
    cout << bs() << '\n';
    
    return 0;
}

bool f(lli x) {
    return ((double)(x / w) * (double)(x / h) >= (double)N);
}

lli bs() {
    lli l = 0LL,
        r = (lli)1e18;
    
    while (l + 1LL < r) {
        lli m = (l + r) / 2LL;

        if (!f(m))
            l = m;
        else
            r = m;
    }

    return r;
}
