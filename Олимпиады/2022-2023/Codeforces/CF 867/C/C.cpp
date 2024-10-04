// author: Danila "akshin_" Aksionov

#include <iostream>
using namespace std;
typedef long long int lli;

lli Q;
lli N;

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
    cin >> N;
    N -= 4LL;
    cout << (26LL + (10LL + N) * N) << '\n';
    return;
}
