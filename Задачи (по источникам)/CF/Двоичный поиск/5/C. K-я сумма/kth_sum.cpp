// author: Danila "akshin_" Aksionov

#include <iostream>
#include <algorithm>
using namespace std;
typedef long long int lli;

#define pb(elem) push_back(elem)
#define mp(_first, _second) make_pair(_first, _second)
#define sz(object) (lli)(object).size()
#define all(object) (object).begin(), (object).end()

const lli MAX_SIZE = (lli)1e5;

lli N,
    A[MAX_SIZE + 5LL],
    B[MAX_SIZE + 5LL],
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
    for (int i = 0; i < (int)N; ++i)
        cin >> A[i];
    for (int i = 0; i < (int)N; ++i)
        cin >> B[i];
    
    sort(A, A + N);
    sort(B, B + N);
    
    answer = bs();
    cout << answer << '\n';
    return;
}

lli bs() {
    lli l = 0LL,
        r = (lli)1e10;
    
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
    for (int i = 0; i < (int)N; ++i)
        _cnt += lower_bound(B, B + N, x - A[i]) - B;
    return _cnt;
}
