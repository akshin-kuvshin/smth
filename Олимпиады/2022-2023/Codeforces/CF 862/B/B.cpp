#include <iostream>
#include <string>
#include <vector>
using namespace std;
typedef long long int lli;
 
const lli MAX_SIZE = 100000LL;
 
lli Q;
lli N;
string S,
       ans;
 
void solve();
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
 
    cin >> Q;
    while (Q--) {
        solve();
    }
    
    return 0;
}
 
void solve() {
    S.clear();
 
    cin >> N;
    for (int i = 0; i < (int)N; ++i) {
        char tmp;
        cin >> tmp;
        S.push_back(tmp);
    }
 
    char _min = S[0];
    for (int i = 1; i < (int)N; ++i)
        _min = min(_min, S[i]);
    
    for (int i = (int)N - 1; i >= 0; --i)
        if (S[i] == _min) {
            ans = "";
            ans += _min;
            ans += S.substr(0, i);
            ans += S.substr(i + 1, (int)N - i - 1);
            break;
        }
    
    cout << ans << '\n';    
    return;
}
