// author: Danila "akshin_" Aksionov

#include <iostream>
using namespace std;
typedef long long int lli;

lli N,
    cur;

void solve();

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    solve();
    
    return 0;
}

void solve() {
    cin >> N;

    while (N--) {
        cout << (char)('a' + cur);
        cur = (cur + 1LL) % 26LL;
    }
    cout << '\n';
    
    return;
}
