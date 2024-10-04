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

    if (N == 2LL) {
        cout << "1 1\n1 2\n";
        return;
    }
    if (N == 3LL) {
        cout << "2 1\n2 3\n3 1\n";
        return;
    }

    for (int i = 1; i <= (int)N - 2; ++i)
        cout << "1 " << i << '\n';
    cout << N << " 2\n";
    cout << N << ' ' << N << '\n';

    return;
}
