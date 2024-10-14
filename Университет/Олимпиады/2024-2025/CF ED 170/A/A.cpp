// author: Danila "akshin_" Axyonov

#include <iostream>
#include <string>
using namespace std;
typedef long long int lli;

#define plli                pair<lli, lli>
#define mp(_first, _second) make_pair(_first, _second)
#define pb(_elem)           push_back(_elem)

lli Q;
string S,
       T;
lli S_len,
    T_len,
    max_pref_len;
lli ans;

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
    max_pref_len = 0LL;

    cin >> S >> T;
    S_len = (lli)S.size();
    T_len = (lli)T.size();
    lli i = 0LL;
    while (i < min(S_len, T_len) and S[i] == T[i]) {
        ++max_pref_len;
        ++i;
    }
    ans = S_len + T_len - max_pref_len + 1LL * (max_pref_len > 0LL);
    cout << ans << '\n';
    return;
}
