// author: Danila "akshin_" Axyonov

#include <iostream>
using namespace std;
typedef long long int lli;

#define plli                pair<lli, lli>
#define mp(_first, _second) make_pair(_first, _second)
#define pb(_elem)           push_back(_elem)

const lli MAX_SIZE = (lli)3e5 + 5LL;

lli N,
    A[MAX_SIZE];
lli r;
lli ans;

void solve();

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    solve();
    
    return 0;
}

void solve() {
    cin >> N >> r;
    for (int i = 0; i < (int)N; ++i)
        cin >> A[i];
    
    lli L = 0LL,
        S = 0LL;
    for (lli R = 1LL; R < N; ++R) {
        S += A[R] - A[R - 1LL];
        while (S - (A[L + 1LL] - A[L]) > r) {
            S -= A[L + 1LL] - A[L];
            ++L;
        }
        if (S > r)
            ans += L + 1LL;
    }
    
    cout << ans << '\n';
    return;
}
