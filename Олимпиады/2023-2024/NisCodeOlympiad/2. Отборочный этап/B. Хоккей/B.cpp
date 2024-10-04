// author: Danila "akshin_" Axyonov

#include <iostream>
#include <string>
using namespace std;
typedef long long int lli;

#define plli                pair<lli, lli>
#define mp(_first, _second) make_pair(_first, _second)
#define pb(_elem)           push_back(_elem)

string S;
string cur;

void solve();

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    solve();
    
    return 0;
}

void solve() {
    cin >> S;

    cur = "0000000";
    if (S.find(cur) != string::npos) {
        cout << "YES\n";
        return;
    }

    cur = "1111111";
    if (S.find(cur) != string::npos) {
        cout << "YES\n";
        return;
    }
    
    cout << "NO\n";
    return;
}
