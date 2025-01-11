// author: Danila "akshin_" Axyonov

#include <iostream>
#include <vector>
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
    size_t n;
    cin >> n;
    vector<lli> a(n);
    for (size_t i = 0ULL; i < n; ++i)
        cin >> a[i];
    
    for (size_t i = 0ULL; i + 1ULL < n; ++i) {
        lli x = a[i],
            y = a[i + 1ULL];
        if (x < 2LL * y and y < 2LL * x) {
            cout << "YES\n";
            return;
        }
    }
    cout << "NO\n";
    return;
}
