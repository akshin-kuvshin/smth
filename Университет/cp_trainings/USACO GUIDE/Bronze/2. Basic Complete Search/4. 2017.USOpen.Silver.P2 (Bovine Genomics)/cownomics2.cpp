// author: Danila "akshin_" Axyonov

#include <fstream>
#include <string>
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
    for (int i = 0; i < (int)m; ++i)
        for (int j = i + 1; j < (int)m; ++j)
            for (int k = j + 1; k < (int)m; ++k) {
                unordered_map<string, bool> spot_m,
                                            norm_m;
                bool flag = false;
                for (int row = 0; row < (int)n; ++row) {
                    string spot_s = to_string(spot[row][i]) + to_string(spot[row][j]) + to_string(spot[row][k]),
                           norm_s = to_string(norm[row][i]) + to_string(norm[row][j]) + to_string(norm[row][k]);
                    spot_m[spot_s] = true;
                    norm_m[norm_s] = true;

                    if (spot_m[norm_s] or norm_m[spot_s]) {
                        flag = true;
                        break;
                    }
                }
                if (flag)
                    continue;

                flag = true;
                for (auto [s, was] : spot_m) {
                    if (not was)
                        continue;
                    if (norm_m[s]) {
                        flag = false;
                        break;
                    }
                }
                ans += flag;
            }
    cout << ans << '\n';

    cin.close();
    cout.close();
    return;
}
