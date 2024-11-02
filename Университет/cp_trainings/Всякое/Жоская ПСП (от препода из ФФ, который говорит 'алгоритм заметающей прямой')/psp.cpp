// author: Danila "akshin_" Axyonov

#include <iostream>
#include <string>
using namespace std;
typedef long long int lli;

#define plli                pair<lli, lli>
#define mp(_first, _second) make_pair(_first, _second)
#define pb(_elem)           push_back(_elem)

const lli MAX_SIZE = (lli)1e5 + 5LL;

lli Q;
string S;
lli cnt;

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
    cin >> S; // вводите без пробелов, пожалуйста(

    cnt = 0LL;
    for (char c : S) {
        if (c == '(')
            ++cnt;
        else if (c == ')')
            --cnt;
        if (cnt < 0LL) {
            cout << "NO\n";
            return;
        }
    }
    cout << (!cnt ? "YES\n" : "NO\n");

    return;
}
