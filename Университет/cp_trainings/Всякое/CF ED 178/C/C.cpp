// author: Danila "akshin_" Axyonov

#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
using lli = long long int;

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
    lli n;
    cin >> n;
    string S;
    cin >> S;

    lli B = (lli)count(S.begin(), S.end(), 'B');
    
    lli A_victory =
        ((S.front() == 'A' and (S.back() == 'A' or B == 1LL)) or
         (S[(int)n - 2] == 'A' and S.back() == 'A'));
    cout << (A_victory ? "Alice" : "Bob") << '\n';

    return;
}
