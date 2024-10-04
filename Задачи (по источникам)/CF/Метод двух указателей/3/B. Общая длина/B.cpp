// author: Danila "akshin_" Axyonov

#include <iostream>
using namespace std;
typedef long long int lli;

#define plli                pair<lli, lli>
#define mp(_first, _second) make_pair(_first, _second)
#define pb(_elem)           push_back(_elem)

const lli MAX_SIZE = (lli)1e5 + 5LL;

lli N,
    A[MAX_SIZE];
lli S;
lli ans;

void solve();

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    solve();
    
    return 0;
}

void solve() {
    cin >> N >> S;
    for (int i = 0; i < (int)N; ++i)
        cin >> A[i];
    
    lli L = 0LL,
        _S = 0LL;
    for (lli R = 0LL; R < N; ++R) {
        _S += A[R];
        while (_S > S)
            _S -= A[L++];
        lli k = R - L + 1LL;
        ans += k * (k + 1LL) / 2LL;
    }
    
    cout << ans << '\n';
    return;
}
