// author: Danila "akshin_" Axyonov

#include <fstream>
#include <vector>
#include <unordered_map>
using namespace std;
using lli = long long int;

#define plli                pair<lli, lli>
#define mp(_first, _second) make_pair(_first, _second)
#define pb(_elem)           push_back(_elem)

void solve();

int main() {
    ios::sync_with_stdio(false);
    
    solve();
    
    return 0;
}

void solve() {
    ifstream cin("cownomics.in");
    cin.tie(nullptr);
    ofstream cout("cownomics.out");

    lli n,
        m;
    cin >> n >> m;
    vector<vector<char>> spot(n, vector<char>(m)),
                         norm(n, vector<char>(m));
    for (int i = 0; i < (int)n; ++i)
        for (int j = 0; j < (int)m; ++j)
            cin >> spot[i][j];
    for (int i = 0; i < (int)n; ++i)
        for (int j = 0; j < (int)m; ++j)
            cin >> norm[i][j];
    
    lli ans = 0LL;
    for (int pos = 0; pos < (int)m; ++pos) {
        unordered_map<char, bool> spot_m,
                                  norm_m;
        for (int i = 0; i < (int)n; ++i) {
            spot_m[spot[i][pos]] = true;
            norm_m[norm[i][pos]] = true;
        }

        bool flag = true;
        for (char c : "ACGT")
            flag = flag && (not (spot_m[c] && norm_m[c]));
        ans += flag;
    }
    cout << ans << '\n';

    cin.close();
    cout.close();
    return;
}
