// author: Danila "akshin_" Aksionov

#include <iostream>
#include <algorithm>
using namespace std;
typedef long long int lli;

#define plli                pair<lli, lli>
#define mp(_first, _second) make_pair(_first, _second)
#define pb(_elem)           push_back(_elem)

const lli MAX_SIZE = (lli)1e6 + 5LL;

lli N;
lli divs[MAX_SIZE],
    top;
lli ans;

void solve();
lli gcd_R(lli, lli);

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    solve();
    
    return 0;
}

void solve() {
    cin >> N;

    for (lli d = 1LL; d * d <= N; ++d)
        if (N % d == 0LL) {
            divs[top++] = d;
            if (d * d != N)
                divs[top++] = N / d;
        }
    sort(divs, divs + top);

    for (int i = 0; i < (int)top; ++i)
        for (int j = i + 1; (j < (int)top) and (divs[i] * divs[j] <= N); ++j)
            if (gcd_R(divs[i], divs[j]) == 1LL)
                ++ans;
    
    cout << ans << '\n';
    return;
}

lli gcd_R(lli a, lli b) {
    return ((a && b) ? gcd_R(b, a % b) : (a | b));
}
