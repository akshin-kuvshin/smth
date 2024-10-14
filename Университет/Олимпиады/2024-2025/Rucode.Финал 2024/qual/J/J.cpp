// author: Danila "akshin_" Axyonov
// Пытался сделать что-то с хэшами, но не вышло(

#include <iostream>
#include <algorithm>
using namespace std;
typedef long long int lli;

#define plli                pair<lli, lli>
#define mp(_first, _second) make_pair(_first, _second)
#define pb(_elem)           push_back(_elem)

const lli MAX_SIZE = (lli)1e5 + 5LL,
          P = (lli)1e5 + 3LL,
          MOD = (lli)1e9 + 7LL;
lli POW[MAX_SIZE];

lli N,
    A[MAX_SIZE],
    rev_A[MAX_SIZE],
    M;
lli _hash[MAX_SIZE],
    rev_hash[MAX_SIZE];

void solve();
lli get_hash(lli*, lli, lli);

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    POW[0] = 1LL;
    for (int i = 1; i < (int)MAX_SIZE; ++i)
        POW[i] = (POW[i - 1] * P) % MOD;
    
    solve();
    
    return 0;
}

void solve() {
    cin >> N >> M;
    for (int i = 0; i < (int)N; ++i)
        cin >> A[i];
    copy(A, A + N, rev_A);

    _hash[0] = rev_hash[0] = 0LL;
    for (int i = 0; i < (int)N; ++i) {
        _hash[i + 1] = (_hash[i] + (A[i] * POW[i]) % MOD) % MOD;
        rev_hash[i + 1] = (rev_hash[i] + (rev_A[i] * POW[i]) % MOD) % MOD;
    }
    
    for (int i = (int)(N >> 1); i >= 0; --i) {
        if (get_hash(_hash, 0LL, (lli)i) == get_hash(rev_hash, N - 2LL * (lli)i, N - (lli)i))
            cout << N - i << ' ';
    }
    cout << '\n';

    return;
}

lli get_hash(lli *h, lli l, lli r) {
    return h[r] - h[l];
}
