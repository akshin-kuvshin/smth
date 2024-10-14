// author: Danila "akshin_" Axyonov

#include <iostream>
#include <string>
using namespace std;
typedef long long int lli;

#define plli                pair<lli, lli>
#define mp(_first, _second) make_pair(_first, _second)
#define pb(_elem)           push_back(_elem)

lli l = 1LL,
    r;
string ans;

void solve();

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    solve();
    
    return 0;
}

void solve() {
    cin >> r;
    ++r;

    while (l + 1LL < r) {
        lli m = (l + r) >> 1;
        cout << "? " << m << endl;
        cin >> ans;
        if (ans == "<")
            r = m;
        else // ans == ">="
            l = m;
    }
    cout << "! " << l << endl;
    
    return;
}
