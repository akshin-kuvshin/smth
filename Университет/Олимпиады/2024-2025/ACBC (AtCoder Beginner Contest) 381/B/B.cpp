// author: Danila "akshin_" Axyonov

#include <iostream>
#include <string>
#include <map>
using namespace std;
typedef long long int lli;

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
    lli N = (lli)S.size();
    
    if (N & 1LL) {
        cout << "No\n";
        return;
    }
    
    map<char, bool> m;
    for (int i = 0; i < ((int)N >> 1); ++i) {
        int i1 = 2 * i,
            i2 = 2 * i + 1;
        if (S[i1] != S[i2]) {
            cout << "No\n";
            return;
        }
        if (m[S[i1]]) {
            cout << "No\n";
            return;
        }
        m[S[i1]] = true;
    }
    cout << "Yes\n";
    return;
}
