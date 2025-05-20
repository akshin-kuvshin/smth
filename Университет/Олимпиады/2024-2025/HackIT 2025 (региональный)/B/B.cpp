// author: Danila "akshin_" Axyonov

#include <iostream>
#include <string>
#include <vector>
#include <queue>
using namespace std;
using lli = long long int;
using plli = pair<lli, lli>;

const vector<plli> d = {{-1LL, 0LL}, {1LL, 0LL}, {0LL, -1LL}, {0LL, 1LL}};

void solve();

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	solve();
	
	return 0;
}

void solve() {
    lli n,
        m;
    cin >> n >> m;
    vector<string> a(n);
    for (int i = 0; i < (int)n; ++i)
        cin >> a[i];
    
    vector<vector<bool>> cleaned(n, vector<bool>(m));
    for (int _ = 0; _ < (int)(n + m - 2LL); ++_)
    {
        vector<string> b = a;
        for (lli i = 0LL; i < n; ++i)
            for (lli j = 0LL; j < m; ++j) {
                if (a[i][j] == 'x')
                    continue;
                bool has_bad_nb = false;
                for (plli dd : d) {
                    lli ii = i + dd.first,
                        jj = j + dd.second;
                    if (ii < 0LL or n <= ii or jj < 0LL or m <= jj)
                        continue;
                    if (a[ii][jj] == 'x') {
                        has_bad_nb = true;
                        break;
                    }
                }
                if (not has_bad_nb)
                    continue;
                if (a[i][j] == '.')
                    b[i][j] = 'x';
                else // a[i][j] == 'o'
                    cleaned[i][j] = true;
            }
        a = b;
        
        lli ans = 0LL;
        for (lli i = 0LL; i < n; ++i)
            for (lli j = 0LL; j < m; ++j)
                ans += cleaned[i][j];
        cout << ans << ' ';
    }
    cout << '\n';
	return;
}
