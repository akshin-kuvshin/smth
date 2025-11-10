// author: Danila "akshin_" Axyonov

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long int lli;

#define mp(arg1, arg2)      make_pair(arg1, arg2)
#define pb(arg)             push_back(arg)

void solve();

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}

void solve() {
    lli n,
        x;
    cin >> n >> x;
    vector<lli> a(n);
    for (lli& ai : a)
        cin >> ai;
    
    lli sum = 0LL;
    for (lli ai : a)
        sum += ai;
    
    int ans_ind = -1;
    for (int i = 0; i < (int)n; ++i)
        if (-sum + n * a[i] == x) {
            ans_ind = i;
            break;
        }
    
    if (ans_ind == -1)
        cout << "-1\n";
    else {
        for (int i = 0; i < ans_ind; ++i)
            cout << a[i] << ' ';
        for (int i = ans_ind + 1; i < (int)n; ++i)
            cout << a[i] << ' ';
        cout << a[ans_ind] << '\n';
    }
    return;
}

