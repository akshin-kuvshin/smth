// author: Danila "akshin_" Axyonov

#include <iostream>
using namespace std;
using lli = long long int;

#define plli                pair<lli, lli>
#define mp(_first, _second) make_pair(_first, _second)
#define pb(_elem)           push_back(_elem)

void solve();

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    solve();
    
    return 0;
}

void solve() {
    lli n;
    cin >> n;
    lli R = 0LL,
        S = 0LL,
        P = 0LL;
    char c;
    while (n) {
        cin >> c;
        if (c == 'R') {
            ++R;
            --n;
        } else if (c == 'S') {
            ++S;
            --n;
        } else if (c == 'P') {
            ++P;
            --n;
        }
    }
    lli ans;
    if ((not R and not S) or (not S and not P) or (not R and not P))
        ans = 0LL;
    else if (not R)
        ans = P;
    else if (not S)
        ans = R;
    else if (not P)
        ans = S;
    else
        ans = min(min(
            S + 2LL * P,
            P + 2LL * R),
            R + 2LL * S
        );
    cout << ans << '\n';
    return;
}
