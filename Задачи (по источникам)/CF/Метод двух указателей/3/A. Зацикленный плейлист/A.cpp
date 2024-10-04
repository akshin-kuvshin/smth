// author: Danila "akshin_" Axyonov

#include <iostream>
#include <algorithm>
using namespace std;
typedef long long int lli;

#define plli                pair<lli, lli>
#define mp(_first, _second) make_pair(_first, _second)
#define pb(_elem)           push_back(_elem)

const lli MAX_SIZE = (lli)2e3 + 5LL,
          INF = (lli)1e18 + 1LL;

lli N,
    A[MAX_SIZE],
    A_sum;
lli p,
    k;
plli ans = mp(INF, -1LL); // first: len;   second: start_ind

void solve();

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    solve();
    
    return 0;
}

void solve() {
    cin >> N >> p;
    for (int i = 0; i < (int)N; ++i) {
        cin >> A[i];
        A_sum += A[i];
    }
    
    k = p / A_sum;
    p %= A_sum;

    if (p == 0LL)
        ans = mp(0LL, 0LL);
    else {
        copy(A, A + N, A + N);
        lli L = 0LL,
            S = 0LL;
        for (lli R = 0LL; R < 2LL * N; ++R) {
            S += A[R];
            while (S - A[L] >= p)
                S -= A[L++];
            if (S >= p)
                ans = min(ans, mp(R - L + 1LL, L % N));
        }
    }
    
    cout << (ans.second + 1LL) << ' ' << (ans.first + N * k) << '\n';
    return;
}
