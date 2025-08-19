// author: Danila "akshin_" Axyonov

#include <iostream>
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
    lli ans = 0LL;

    lli d;
    for (int i = 0; i <= 29; ++i) {
        // 100'500 submissions was failed because I've forgotten to output '?' sign before the number in the code line below...
        cout << "? " << (1LL << i) << endl;
        cin >> d;

        if (d <= 0LL) {
            ans += (1LL << (i - (int)d + 1)) - (1LL << i);
            i = i - (int)d + 1;
        }
    }

    cout << "! " << ans << endl;
    return;
}
