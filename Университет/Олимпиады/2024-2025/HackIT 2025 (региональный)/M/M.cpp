// author: Danila "akshin_" Axyonov

#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;
using lli = long long int;

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
    vector<lli> h(n);
    for (lli& hi : h)
        cin >> hi;
    vector<lli> c(n);
    for (lli& ci : c)
        cin >> ci;
    
    set<lli> h_unique_set;
    for (lli hi : h)
        h_unique_set.insert(hi);
    vector<lli> h_unique;
    copy(h_unique_set.begin(), h_unique_set.end(), back_inserter(h_unique));
    
    vector<vector<lli>> dp(n, vector<lli>(h_unique.size())),
                        p_min(n, vector<lli>(h_unique.size()));
    dp[0][0] = p_min[0][0] = abs(h[0] - h_unique[0]) * c[0];
    for (int j = 1; j < (int)h_unique.size(); ++j) {
        dp[0][j] = abs(h[0] - h_unique[j]) * c[0];
        p_min[0][j] = min(p_min[0][j - 1], dp[0][j]);
    }
    for (int i = 1; i < (int)n; ++i) {
        dp[i][0] = p_min[i][0] = p_min[i - 1][0] + abs(h[i] - h_unique[0]) * c[i];
        for (int j = 1; j < (int)h_unique.size(); ++j) {
            dp[i][j] = p_min[i - 1][j] + abs(h[i] - h_unique[j]) * c[i];
            p_min[i][j] = min(p_min[i][j - 1], dp[i][j]);
        }
    }
    
    cout << p_min.back().back() << '\n';
	return;
}
