// author: Danila "akshin_" Axyonov

#include <iostream>
#include <algorithm>
using namespace std;
typedef long long int lli;

#define plli                pair<lli, lli>
#define mp(_first, _second) make_pair(_first, _second)
#define pb(_elem)           push_back(_elem)

const lli MAX_SIZE = (lli)1e5 + 5LL;

lli Q;
lli N,
    A[MAX_SIZE];
bool f[MAX_SIZE];

void solve();

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin >> Q;
    while (Q--)
        solve();
    
    return 0;
}

void solve() {
    cin >> N;
    for (int i = 0; i < (int)N; ++i) {
        cin >> A[i];
        --A[i];
    }

    fill(f, f + N, false);
    for (int i = 0; i < (int)N; ++i)
        if (!f[A[i]])
            f[A[i]] = true;
        else if (!f[N - 1LL - A[i]])
            f[N - 1LL - A[i]] = true;
        else {
            cout << "NO\n";
            return;
        }
    
    cout << "YES\n";
    return;
}
