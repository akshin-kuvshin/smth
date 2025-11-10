// author: Danila "akshin_" Axyonov

#include <iostream>
using namespace std;
typedef long long int lli;

void solve();

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}

void solve() {
    lli t,
        my_p,
        s,
        p,
        att;
    cin >> t >> my_p >> s >> p >> att;
    p += (9LL - s) * t + 20LL * att;
    cout << (lli)(bool)(p >= my_p) << '\n';
    return;
}
