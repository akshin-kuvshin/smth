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
    vector<lli> x(n),
                y(n);
    for (auto& xi : x)
        cin >> xi;
    for (auto& yi : y)
        cin >> yi;
    
    lli max_dist = 0LL;
    for (int i = 0; i < (int)n; ++i)
        for (int j = i + 1; j < (int)n; ++j)
            max_dist = max(max_dist, (x[i] - x[j]) * (x[i] - x[j]) + (y[i] - y[j]) * (y[i] - y[j]));
    cout << max_dist << '\n';
    
    return;
}
