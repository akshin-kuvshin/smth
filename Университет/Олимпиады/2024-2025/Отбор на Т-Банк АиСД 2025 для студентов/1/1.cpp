// author: Danila "akshin_" Axyonov

#include <iostream>
#include <vector>
using namespace std;
using lli = long long int;

#define plli                pair<lli, lli>
#define mp(_first, _second) make_pair(_first, _second)
#define pb(_elem)           push_back(_elem)

void solve();

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    solve();
    
    return 0;
}

void solve() {
    lli n,
        a;
    cin >> n >> a;
    vector<lli> t(n);
    for (int i = 0; i < (int)n; ++i)
        cin >> t[i];
    
    lli cur_t = 0LL;
    for (int i = 0; i < (int)n; ++i) {
        if (cur_t < t[i])
            cur_t = t[i];
        cur_t += a;
        cout << cur_t << '\n';
    }    
    
    return;
}
