// author: Danila "akshin_" Axyonov

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
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

    string cur;
    int ans = 0;
    for (char c : S) {
        cur += c;
        string rev_cur = cur;
        reverse(rev_cur.begin(), rev_cur.end());
        vector<int> p = prefix(rev_cur);
        int p_max = *max_element(p.begin(), p.end());
        ans += (int)cur.size() - p_max;
    }
    
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
