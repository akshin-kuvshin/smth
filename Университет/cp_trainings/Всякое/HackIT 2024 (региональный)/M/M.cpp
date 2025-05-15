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
    string s1;
    lli t1;
    cin >> s1;
    if (s1 == "accurately")
        t1 = 0LL;
    else {
        cin >> t1;
        if (s1 == "late")
            t1 = -t1;
    }

    string s2;
    lli t2;
    cin >> s2;
    if (s2 == "accurately")
        t2 = 0LL;
    else {
        cin >> t2;
        if (s2 == "late")
            t2 = -t2;
    }

    lli dt = t2 - t1;
    if (not dt)
        cout << "together";
    else if (dt < 0LL)
        cout << "Chipy-chipy " << -dt;
    else // dt > 0LL
        cout << "Chapa-chapa " << dt; 
    cout << '\n';
    return;
}
