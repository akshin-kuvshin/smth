// author: Danila "akshin_" Axyonov

#include <iostream>
#include <string>
#include <map>
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
    
    map<char, lli> m; // можно было и без мапы
    lli len = (lli)S.size();
    for (lli i = 0LL; i < len; ++i)
        m[S[i]] += (i + 1LL) * (len - i);
    
    for (auto [c, cnt] : m)
        cout << c << ": " << cnt << '\n';
    
    return;
}
