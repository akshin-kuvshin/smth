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
    
    lli l = 0LL,
        sum = 0LL;
    for (lli r = 0LL; r < N; ++r) {
        sum += A[r];
        while (sum - A[l] >= S)
            sum -= A[l++];
        if (sum >= S)
            ans += l + 1LL;
    }
    
    cout << ans << '\n';
    return;
}
