// author: Danila "akshin_" Axyonov
// пысы: это нихуя не метод двух указателей, потому что я не ебу, как его здесь применить в явном виде.

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
    pA[MAX_SIZE],
    A_weight,
    M,
    B[MAX_SIZE],
    pB[MAX_SIZE],
    B_weight;
lli W_max;
lli ans; // S_max

void solve();

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    solve();
    
    return 0;
}

void solve() {
    cin >> N >> M >> W_max >> A_weight >> B_weight;
    for (int i = 0; i < (int)N; ++i)
        cin >> A[i];
    for (int i = 0; i < (int)M; ++i)
        cin >> B[i];
    
    sort(A, A + N, greater<lli>());
    sort(B, B + M, greater<lli>());

    for (int i = 0; i < (int)N; ++i)
        pA[i + 1] = pA[i] + A[i];
    for (int i = 0; i < (int)M; ++i)
        pB[i + 1] = pB[i] + B[i];

    lli _x = min(N, W_max / A_weight);
    for (lli x = 0LL; x <= _x; ++x) {
        lli y = min(M, (W_max - A_weight * x) / B_weight);
        ans = max(ans, pA[x] + pB[y]);
    }
    
    cout << ans << '\n';
    return;
}
