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
    lli n,
        m,
        k;
    cin >> n >> m >> k;
    vector<lli> a(m),
                q(k);
    for (int i = 0; i < (int)m; ++i)
        cin >> a[i];
    for (int i = 0; i < (int)k; ++i)
        cin >> q[i];
    
    if (k == n) {
        for (int i = 0; i < (int)m; ++i)
            cout << '1';
        cout << '\n';
        return;
    }
    if (k < n - 1LL) {
        for (int i = 0; i < (int)m; ++i)
            cout << '0';
        cout << '\n';
        return;
    }
    // now k == n - 1LL

    lli n_sum = n * (n + 1LL) / 2LL;
    lli q_sum = 0LL;
    for (int i = 0; i < (int)k; ++i)
        q_sum += q[i];
    lli unknown = n_sum - q_sum;

    for (int i = 0; i < (int)m; ++i)
        cout << ((a[i] == unknown) ? '1' : '0'); // раньше здесь было "? '0' : '1'"...
    cout << '\n';    
    return;
}
