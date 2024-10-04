// author: Danila "akshin_" Axyonov

#include <iostream>
#include <unordered_map>
using namespace std;
typedef long long int lli;

#define plli                pair<lli, lli>
#define mp(_first, _second) make_pair(_first, _second)
#define pb(_elem)           push_back(_elem)

const lli MAX_SIZE = (lli)1e5 + 5LL;

lli N,
    A[MAX_SIZE];
lli K;
unordered_map<lli, lli> m;
lli ans;

void solve();

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    solve();
    
    return 0;
}

void solve() {
    cin >> N >> K;
    for (int i = 0; i < (int)N; ++i)
        cin >> A[i];
    
    lli L = 0LL,
        cnt = 0LL;
    for (lli R = 0LL; R < N; ++R) {
        ++m[A[R]];
        if (m[A[R]] == 1LL)
            ++cnt;
        
        while (cnt > K) {
            --m[A[L]];
            if (m[A[L]] == 0LL) {
                --cnt;
                m.erase(A[L]);
            }
            ++L;
        }

        ans += R - L + 1LL;
    }
    
    cout << ans << '\n';
    return;
}
