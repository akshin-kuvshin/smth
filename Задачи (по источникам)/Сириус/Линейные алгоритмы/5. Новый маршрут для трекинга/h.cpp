// author: Danila "akshin_" Aksionov

#include <iostream>
using namespace std;
typedef long long int lli;

#define plli                pair<lli, lli>
#define mp(_first, _second) make_pair(_first, _second)
#define pb(_elem)           push_back(_elem)

// Сдал задачу только с 5-ой попытки, потому что неверно объявил константу...
const lli MAX_SIZE = (lli)2e5 + 5LL;

lli N,
    A[MAX_SIZE],
    pref[MAX_SIZE];
lli Q,
    l,
    r,
    ans;

void solve();

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    solve();
    
    return 0;
}

void solve() {
    cin >> N >> Q;
    for (int i = 0; i < (int)N; ++i)
        cin >> A[i];
    
    // Здесь префиксы считаются на отрезках.
    // Т.е. pref[i] = функция на отрезке [0, i]
    pref[0] = 0LL;
    for (int i = 1; i < (int)N; ++i)
        pref[i] = pref[i - 1] + (A[i - 1] < A[i] ? 1LL : 0LL);
    
    while (Q--) {
        cin >> l >> r;
        --l, --r;
        ans = pref[r] - pref[l];
        cout << ans << endl;
    }
    
    return;
}
