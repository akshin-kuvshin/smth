// author: Danila "akshin_" Axyonov

#include <iostream>
#include <algorithm>
using namespace std;
typedef long long int lli;

#define plli                pair<lli, lli>
#define mp(_first, _second) make_pair(_first, _second)
#define pb(_elem)           push_back(_elem)

const lli MAX_SIZE = (lli)1.5e5 + 5LL,
          len = 400LL,
          INF = (lli)1e18 + 1LL;

lli N,
    A[MAX_SIZE],
    B[len],
    K;

void solve();
lli get_min(lli, lli);

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    solve();
    
    return 0;
}

void solve() {
    fill(B, B + len, INF);

    cin >> N >> K;
    for (int i = 0; i < (int)N; ++i) {
        cin >> A[i];
        B[i / len] = min(B[i / len], A[i]);
    }

    for (int i = 0; i + (int)K <= (int)N; ++i)
        cout << get_min((lli)i, (lli)i + K) << ' ';
    cout << '\n';
    
    return;
}

lli get_min(lli l, lli r) {
    lli m = INF;
    
    lli ind = l;
    while (ind < r)
        if (ind % len == 0LL and ind + len <= r) {
            m = min(m, B[ind / len]);
            ind += len;
        } else
            m = min(m, A[ind++]);

    return m;
}
