// author: Danila "akshin_" Aksionov

#include <iostream>
#include <cmath> // for std::abs
using namespace std;
typedef long long int lli;

#define plli                pair<lli, lli>
#define mp(_first, _second) make_pair(_first, _second)
#define pb(_elem)           push_back(_elem)

const lli MAX_SIZE = (lli)1e5 + 5LL,
          INF = (lli)1e18;

lli N,
    A[MAX_SIZE];
lli M,
    B[MAX_SIZE];
lli d = INF;
plli ans = {-1LL, -1LL};

void solve();
lli nearest(lli);

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    solve();
    
    return 0;
}

void solve() {
    cin >> N;
    for (int i = 0; i < (int)N; ++i)
        cin >> A[i];
    
    cin >> M;
    B[0] = -INF;
    for (int i = 1; i <= (int)M; ++i)
        cin >> B[i];
    B[M + 1LL] = INF;

    for (int i = 0; i < (int)N; ++i) {
        lli _b = nearest(A[i]);
        lli new_d = abs(A[i] - _b);

        if (new_d < d) {
            ans = mp(A[i], _b);
            d = new_d;
        }
    }
    
    cout << ans.first << ' ' << ans.second << '\n';
    return;
}

lli nearest(lli x) {
    lli l = 0LL, // B[l] <= x
        r = M + 1LL; // x < B[r]
    while (l + 1LL < r) {
        lli mid = (l + r) >> 1;
        if (B[mid] <= x)
            l = mid;
        else
            r = mid;
    }

    lli dl = abs(x - B[l]),
        dr = abs(x - B[r]);
    if (dl < dr)
        return B[l];
    return B[r];
}
