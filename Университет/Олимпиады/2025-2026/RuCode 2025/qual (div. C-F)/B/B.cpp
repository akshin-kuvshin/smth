// author: Danila "akshin_" Axyonov

#include <iostream>
#include <string>
#include <sstream>
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
    string S;
    cin >> S;

    if ((lli)S.size() == 8LL) {
        lli h = 10LL * (lli)(S[0] - '0') + (lli)(S[1] - '0'),
            m = 10LL * (lli)(S[3] - '0') + (lli)(S[4] - '0'),
            s = 10LL * (lli)(S[6] - '0') + (lli)(S[7] - '0');
        
        lli ans = h * 3'600LL + m * 60LL + s;
        cout << ans << '\n';

        return;
    }

    stringstream SS;
    lli t;

    SS << S;
    SS >> t;

    lli h = t / 3'600LL;
    t -= h * 3'600LL;
    lli m = t / 60LL,
        s = t % 60LL;
    
    if (h < 10LL)
        cout << '0';
    cout << h << ':';
    if (m < 10LL)
        cout << '0';
    cout << m << ':';
    if (s < 10LL)
        cout << '0';
    cout << s << '\n';
    
    return;
}
