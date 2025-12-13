// author: Danila "akshin_" Axyonov

#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

void solve();

int main() {
    int q;
    cin >> q;
    while (q--)
        solve();
    return 0;
}

void solve() {
    int n;
    cin >> n;
    string S;
    cin >> S;

    char c = S.back();
    int cnt = (int)count(S.begin(), S.end(), c);
    int ans = n - cnt;
    cout << ans << '\n';
}
