#include <iostream>
#include <string>
using namespace std;
typedef long long int lli;

lli Q;
lli N;
string number;
lli d;
bool flag;

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
    cin >> N >> d >> number;

    flag = false;
    for (int i = 0; i < (int)N; ++i) {
        if (!flag and ((number[i] - '0') < d)) {
            cout << d;
            flag = true;
        }
        cout << number[i];
    }
    if (!flag)
        cout << d;
    cout << '\n';

    return;
}
