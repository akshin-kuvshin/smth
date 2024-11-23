// author: Danila "akshin_" Axyonov

#include <iostream>
using namespace std;
typedef long long int lli;

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
    lli A1, N1, M1,
        A2, N2, M2;
    cin >> A1 >> N1 >> M1 >> A2 >> N2 >> M2;

    lli A = (A2 - A1 + 360LL) % 360LL;
    lli N = N1 * M2 + N2 * M1;
    lli M = M1 * M2;

    lli ans = N / M;
    if (A == 0LL) ++ans;
    if (N % M != 0LL) {
        N %= M;
        if (360LL * N >= (360LL - A) * M) ++ans;
    }
    cout << ans << '\n';
    return;
}
