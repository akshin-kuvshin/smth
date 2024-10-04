// author: Danila "akshin_" Aksionov

#include <iostream>
#include <map>
#include <string>
using namespace std;
typedef long long int lli;

#define plli                pair<lli, lli>
#define mp(_first, _second) make_pair(_first, _second)
#define pb(_elem)           push_back(_elem)

map<string, bool> m;
lli N;
string tmp;

void solve();

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    solve();
    
    return 0;
}

void solve() {
    m["OK"] = false;
    m["WA"] = false;
    m["PE"] = false;
    m["RE"] = false;
    m["ML"] = false;
    m["TL"] = false;

    cin >> N;
    while (N--) {
        cin >> tmp;
        m[tmp] = true;
    }

    for (pair<string, bool> p : m)
        if (!p.second)
            cout << p.first << '\n';
    
    return;
}
