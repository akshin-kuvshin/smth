// author: Danila "akshin_" Axyonov
// Due to CF's tests results, it works even faster!

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
    M,
    B[MAX_SIZE];
lli ans;

void solve();

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    solve();
    
    return 0;
}

void solve() {
    cin >> N >> M;
    for (int i = 0; i < (int)N; ++i)
        cin >> A[i];
    for (int j = 0; j < (int)M; ++j)
        cin >> B[j];
    
    for (int j = 0; j < (int)M; ++j)
        ans += upper_bound(A, A + N, B[j]) - lower_bound(A, A + N, B[j]);

    cout << ans << '\n';
    return;
}
