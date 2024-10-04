// author: Danila "akshin_" Axyonov

#include <iostream>
#include <algorithm>
using namespace std;
typedef long long int lli;

/* #define plli                pair<lli, lli>
#define mp(_first, _second) make_pair(_first, _second)
#define pb(_elem)           push_back(_elem) */

const lli MAX_SIZE = (lli)1e5 + 5LL;

lli N,
    A[MAX_SIZE],
    cnt[MAX_SIZE];
lli X[MAX_SIZE],
    top;
lli d,
    ans;

void solve();

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    solve();
    
    return 0;
}

void solve() {
    cin >> N;
    for (int i = 0; i < (int)N; ++i) {
        cin >> A[i];
        ++cnt[A[i]];
    }

    for (int i = 1; i <= (int)N; ++i)
        if (cnt[i])
            X[top++] = cnt[i];
    sort(X, X + top);

    d = 0LL; // сколько коробок мы уже сделали "плохими"
    ans = top; // ответ
    for (int i = 0; i < (int)top; ++i) {
        lli _d = d + X[i],
            _ans = ans - 1LL;
        if (_d <= _ans) {
            d = _d;
            ans = _ans;
        } else
            break;
    }
    
    cout << ans << '\n';
    return;
}
