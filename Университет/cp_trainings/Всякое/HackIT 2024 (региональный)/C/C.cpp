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
    lli N = 6LL;
    vector<lli> a(N);
    for (lli& ai : a)
        cin >> ai;
    a.pb(a[0]); ++N;
    a.pb(a[1]); ++N;

    // вечный post-editorial тильт
    for (int i = 1; i + 1 < (int)N; ++i) {
        lli x = a[i - 1],
            y = a[i],
            z = a[i + 1];
        if (x * y + y * z < x * z) {
            cout << "Non-convex\n";
            return;
        }
    }
    cout << "Convex\n";
    return;
}
