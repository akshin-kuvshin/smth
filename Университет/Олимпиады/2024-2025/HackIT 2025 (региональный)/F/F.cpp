// author: Danila "akshin_" Axyonov

#include <iostream>
#include <string>
#include <vector>
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
    lli n,
        k;
    cin >> n >> k;
    string S;
    cin >> S;
    
    vector<vector<lli>> cnt(n, vector<lli>(n));
    for (int i = 0; i < (int)n; ++i)
        for (int j = i + 1; j < (int)n; ++j)
            cnt[i][j] += (lli)(S[i] != S[j]);
    
    for (int l = 0; l < (int)n; ++l) {
        int i = l - 1,
            j = l + 1;
        while (i >= 0 and j < (int)n) {
            cnt[i][j] += cnt[i + 1][j - 1];
            --i;
            ++j;
        }
        
        i = l - 1,
        j = l;
        while (i >= 0 and j < (int)n) {
            cnt[i][j] += cnt[i + 1][j - 1];
            --i;
            ++j;
        }
    }
    
    lli ans = 0LL;
    for (int i = 0; i < (int)n; ++i)
        for (int j = i; j < (int)n; ++j)
            ans += (lli)(cnt[i][j] <= k);
    cout << ans << '\n';
	return;
}
