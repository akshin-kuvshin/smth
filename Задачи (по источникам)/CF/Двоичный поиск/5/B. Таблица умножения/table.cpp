// author: Danila "akshin_" Aksionov

#include <iostream>
using namespace std;
typedef long long int lli;

#define pb(elem) push_back(elem)
#define mp(_first, _second) make_pair(_first, _second)
#define sz(object) (lli)(object).size()
#define all(object) (object).begin(), (object).end()

lli N,
    K;
lli answer;

void solve();
lli bs();
lli cnt(lli);

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    solve();
    
    return 0;
}

void solve() {
    cin >> N >> K;
    answer = bs();
    cout << answer << '\n';
    return;
}

lli bs() {
    lli l = 0LL,
        r = (lli)1e10 + 1LL;
    
    while (l + 1LL < r) {
        lli mid = (l + r) / 2LL;

        if (cnt(mid) < K)
            l = mid;
        else
            r = mid;
    }

    return l;
}

lli cnt(lli x) {
    lli _cnt = 0LL;
    for (lli i = 1; i <= N; ++i) {
        _cnt += (min(x, i * N + 1LL) - 1LL) / i;
    }
    return _cnt;
}
