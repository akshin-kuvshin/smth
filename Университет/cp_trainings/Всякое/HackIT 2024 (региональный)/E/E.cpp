// author: Danila "akshin_" Axyonov

#include <iostream>
#include <vector>
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
    lli n,
        k;
    cin >> n >> k;
    vector<lli> a(n);
    for (lli& ai : a)
        cin >> ai;
    
    lli zeros = 0LL;
    for (lli ai : a)
        zeros += (lli)(ai == 0LL);
    if (zeros >= k) {
        cout << "0\n";
        return;
    }

    lli _sum = 0LL;
    for (lli ai : a)
        _sum += ai;
    _sum -= n - k;
    cout << _sum << endl;
    return;
}
