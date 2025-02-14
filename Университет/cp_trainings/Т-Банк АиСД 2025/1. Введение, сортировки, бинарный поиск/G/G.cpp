// author: Danila "akshin_" Axyonov

#include <iostream>
#include <vector>
#include <algorithm>
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
    lli n;
    cin >> n;

    if (n == 1LL) {
        cout << "1\n";
        return;
    }

    vector<lli> p(n);
    generate(p.begin(), p.end(), []() { static lli i = 1LL; return i++; });
    swap(p[n - 2LL], p[n - 1LL]);
    for (lli l = n - 1LL; l >= 0LL; --l)
        swap(p[l], p[(l + n - 1LL) >> 1]);
    
    for (auto elem : p)
        cout << elem << ' ';
    cout << '\n';
    return;
}
