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
    int res = 0LL,
        cnt = 0LL;
    while (res != -1LL and cnt < 297LL) {
        cout << "get" << endl;
        cin >> res;
        ++cnt;
    }
    cout << "put 1" << endl << "put 2" << endl;
    cout << "get" << endl;
    cin >> res;
    if (res == 1) cout << "queue";
    else cout << "stack";
    cout << endl;
    return;
}
