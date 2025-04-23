// author: Danila "akshin_" Axyonov

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define pb(_elem) push_back(_elem)

void solve();
vector<int> prefix(const vector<int>& a);

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    solve();
    
    return 0;
}

void solve() {
    int n,
        _;
    cin >> n >> _;
    vector<int> a(n);
    for (int& ai : a)
        cin >> ai;
    
    vector<int> b;
    copy(a.begin(), a.end(), back_inserter(b));
    b.pb(-1);
    reverse(a.begin(), a.end());
    copy(a.begin(), a.end(), back_inserter(b));

    vector<int> p = prefix(b);

    vector<int> ks;
    int k = p.back();
    while (k > 0) {
        ks.pb(k);
        k = p[k - 1];
    }
    ks.pb(0); // === ks.pb(k);

    for (int ksi : ks) {
        if (ksi & 1)
            continue;
        cout << (n - (ksi >> 1)) << ' ';
    }
    cout << '\n';
    
    return;
}

vector<int> prefix(const vector<int>& a) {
    int len = (int)a.size();
    vector<int> p(len);
    for (int i = 1; i < len; ++i) {
        int k = p[i - 1];
        while (k > 0 and a[k] != a[i])
            k = p[k - 1];
        if (a[k] == a[i])
            ++k;
        p[i] = k;
    }
    return p;
}
