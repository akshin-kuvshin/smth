// author: Danila "akshin_" Axyonov

#include <iostream>
using namespace std;
typedef long long int lli;

#define plli                pair<lli, lli>
#define mp(_first, _second) make_pair(_first, _second)
#define pb(_elem)           push_back(_elem)

void solve();

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    lli Q;
    cin >> Q;
    while (Q--)
        solve();
    
    return 0;
}

void solve() {
    lli N;
    cin >> N;

    if (N == 1LL) {
        cout << "1\n";
        return;
    }
    if (N <= 4LL) {
        cout << "2\n";
        return;
    }

    lli cur = 1LL,
        cnt = 1LL;
    while (cur < N) {
        cur = (cur + 1LL) * 2LL;
        ++cnt;
    }
    cout << cnt << '\n';
    return;
}
