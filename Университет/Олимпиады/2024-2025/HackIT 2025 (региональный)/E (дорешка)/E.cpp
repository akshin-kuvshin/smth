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
    lli n;
    cin >> n;

    if (n == 2LL or n == 3LL) {
        cout << "-1\n";
        return;
    }

    vector<vector<lli>> a(n);
    for (int i = 0; i < (int)n; ++i)
        a[i].resize(2 * i + 1);
    
    lli cur = 1LL;
    
    for (int i = 0; i < (int)n - 1; ++i)
        for (int j = 0; j < (int)a[i].size(); j += 2)
            a[i][j] = cur++;
    for (int i = 0; i < (int)n; ++i)
        for (int j = 1; j < (int)a[i].size(); j += 2)
            a[i][j] = cur++;
    for (int j = 0; j < (int)a.back().size(); j += 2)
        a.back()[j] = cur++;
    
    for (vector<lli>& row : a) {
        for (lli elem : row)
            cout << elem << ' ';
        cout << '\n';
    }
    
    return;
}
