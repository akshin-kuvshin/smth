// author: Danila "akshin_" Axyonov

#include <iostream>
#include <algorithm>
using namespace std;
typedef long long int lli;

#define plli                pair<lli, lli>
#define mp(_first, _second) make_pair(_first, _second)
#define pb(_elem)           push_back(_elem)

const lli MAX_SIZE = (lli)1e5 + 5LL;

lli N,
    A[MAX_SIZE],
    W,
    H;
lli ans;

void solve();
lli bs();
bool f(lli);

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    solve();
    
    return 0;
}

void solve() {
    cin >> N >> W >> H;
    for (int i = 0; i < (int)N; ++i)
        cin >> A[i];
    
    ans = bs();
    cout << ans << '\n';
    return;
}

lli bs() {
    lli l = 1LL,
        r = W / *max_element(A, A + N) + 1LL;
    while (l + 1LL < r) {
        lli mid = (l + r) >> 1;
        if (f(mid))
            l = mid;
        else
            r = mid;
    }
    return l;
}

bool f(lli x) {
    lli rows = 1LL;

    lli len = 0LL;
    for (int i = 0; i < (int)N; ++i) {
        if (len == 0LL)
            len += x * A[i];
        else {
            if (len + x * (1LL + A[i]) <= W)
                len += x * (1LL + A[i]);
            else {
                len = x * A[i];
                ++rows;
            }
        }
    }

    return (x * rows <= H);
}
