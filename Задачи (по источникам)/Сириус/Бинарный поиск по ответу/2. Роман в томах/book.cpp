// author: Danila "akshin_" Aksionov

#include <iostream>
using namespace std;
typedef long long int lli;

#define plli                pair<lli, lli>
#define mp(_first, _second) make_pair(_first, _second)
#define pb(_elem)           push_back(_elem)

const lli MAX_SIZE = (lli)1e5 + 5LL;

lli N,
    A[MAX_SIZE];
lli K;
lli ans;

void solve();
bool f(lli);
lli bs();

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
    cin >> K;

    ans = bs();
    cout << ans << '\n';
    return;
}

bool f(lli x) {
    lli cnt = 0LL,
        V = 0LL;
    for (int i = 0; i < (int)N; ++i) {
        if (A[i] > x)
            return false;
        
        if (V + A[i] > x) {
            ++cnt;
            V = A[i];
        } else // V + A[i] <= x
            V += A[i];
    }
    ++cnt;
    return (cnt <= K);
}

lli bs() {
    lli l = 0LL,
        r = (lli)1e16;
    while (l + 1LL < r) {
        lli mid = (l + r) >> 1;
        if (f(mid))
            r = mid;
        else
            l = mid;
    }
    return r;
}
