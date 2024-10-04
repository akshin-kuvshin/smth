// author: Danila "akshin_" Axyonov

#include <iostream>
#include <vector>
using namespace std;
typedef long long int lli;

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
    lli n;
    cin >> n;

    vector<char> c(n);
    for (char &_c : c)
        cin >> _c;

    lli mmax = 0LL,
        mmin = 0LL;
    for (int i = 0; i < (int)n; ++i) {
        if (c[i] == '+')
            mmax += (1LL << i);
        else // c[i] == '-'
            mmin -= (1LL << i);
    }
    
    cout << mmin << ' ' << mmax << '\n';
    return;
}
