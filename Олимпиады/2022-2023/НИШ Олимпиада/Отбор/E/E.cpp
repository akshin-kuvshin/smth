#include <iostream>
#include <string>
using namespace std;
typedef long long int lli;

lli Q;
string _s;

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
    cin >> _s;

    cout << _s[0];
    for (int i = 2; i < (int)_s.size(); i += 2)
        cout << _s[i];
    cout << _s[(int)_s.size() - 1] << '\n';

    return;
}
