// author: Danila "akshin_" Axyonov

#include <iostream>
#include <string>
#include <vector>
using namespace std;

void solve();
vector<int> prefix(const string& S);

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    solve();
    
    return 0;
}

void solve() {
    string S;
    cin >> S;
    vector<int> p = prefix(S);
    int ans = (int)S.size() - p.back();
    cout << ans << '\n';
    return;
}

vector<int> prefix(const string& S) {
    int n = (int)S.size();
    vector<int> p(n);
    for (int i = 1; i < n; ++i) {
        int k = p[i - 1];
        while (k > 0 and S[k] != S[i])
            k = p[k - 1];
        if (S[k] == S[i])
            ++k;
        p[i] = k;
    }
    return p;
}
