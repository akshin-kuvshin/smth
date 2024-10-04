// author: Danila "akshin_" Aksionov

#include <iostream>
using namespace std;
typedef long long int lli;

#define plli                pair<lli, lli>
#define mp(_first, _second) make_pair(_first, _second)
#define pb(_elem)           push_back(_elem)

lli N,
    f;

void solve();

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    solve();
    
    return 0;
}

void solve() {
    cin >> N;

    f = 1LL;
    for (lli num = 2LL; num <= N; ++num) {
        f *= num;
        while (f % 10LL == 0LL)
            f /= 10LL;
        f %= (lli)1e12; // чтобы сохранять двойки (которые в разложении)
    }
    
    f %= 10LL;
    cout << f << '\n';
    return;
}
