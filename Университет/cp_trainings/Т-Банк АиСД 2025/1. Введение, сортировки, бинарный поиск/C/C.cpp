// author: Danila "akshin_" Axyonov

#include <iostream>
#include <string>
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
    lli n;
    cin >> n;

    lli l = 1LL,
        r = n + 1LL;
    string ans;
    while (l + 1LL < r) {
        lli m = (l + r) >> 1;
        cout << m << endl;
        cin >> ans;
        if (ans == "<")
            r = m;
        else // ans == ">="
            l = m;
    }
    cout << "! " << l << endl;
    return;
}
