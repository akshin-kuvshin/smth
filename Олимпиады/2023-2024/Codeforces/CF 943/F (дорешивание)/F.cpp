// author: Danila "akshin_" Axyonov

#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;
typedef long long int lli;

#define plli                pair<lli, lli>
#define mp(_first, _second) make_pair(_first, _second)
#define pb(_elem)           push_back(_elem)

void solve();

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    lli Q;
    cin >> Q;
    while (Q--)
        solve();
    
    return 0;
}

void solve() {
    lli N,
        Q;
    cin >> N >> Q;
    vector<lli> A(N);
    for (int i = 0; i < (int)N; ++i)
        cin >> A[i];
    
    vector<lli> X(N + 1LL);
    X[0] = 0LL;
    for (int i = 0; i < (int)N; ++i)
        X[i + 1] = X[i] ^ A[i];
    
    map<lli, vector<lli>> ind;
    for (int i = 0; i <= (int)N; ++i)
        ind[X[i]].pb((lli)i);
    
    while (Q--) {
        lli l,
            r;
        cin >> l >> r;
        --l;

        if (X[l] == X[r]) {
            cout << "YES\n";
            continue;
        }

        auto p = upper_bound(ind[X[r]].begin(), ind[X[r]].end(), l);
        if (p == ind[X[r]].end() or *p >= r) {
            cout << "NO\n";
            continue;
        }
        auto q = upper_bound(ind[X[l]].begin(), ind[X[l]].end(), *p);
        if (q == ind[X[l]].end() or *q > r) {
            cout << "NO\n";
            continue;
        }
        cout << "YES\n";
    }
    
    return;
}
