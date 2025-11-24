// author: Danila "akshin_" Axyonov

#include <iostream>
#include <vector>
#include <algorithm>
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
    const lli N = 3LL;
    vector<lli> A(N);
    for (int i = 0; i < (int)N; ++i)
        cin >> A[i];
    
    sort(A.begin(), A.end());

    lli ans = max(A[2] - (A[0] + A[1] - 1LL), 0LL);
    cout << ans << '\n';
    return;
}
