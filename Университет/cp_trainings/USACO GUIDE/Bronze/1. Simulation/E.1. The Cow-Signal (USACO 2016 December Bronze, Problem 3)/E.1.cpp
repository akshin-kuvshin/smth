// author: Danila "akshin_" Axyonov

#include <fstream>
#include <vector>
using namespace std;
typedef long long int lli;

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
    ifstream cin;
    cin.open("cowsignal.in");
    cin.tie(nullptr);
    ofstream cout;
    cout.open("cowsignal.out");

    lli n,
        m,
        k;
    cin >> n >> m >> k;
    vector<vector<char>> a(n, vector<char>(m));
    for (int i = 0; i < (int)n; ++i)
        for (int j = 0; j < (int)m; ++j)
            cin >> a[i][j];
    
    vector<vector<char>> b(k * n, vector<char>(k * m));
    for (int i = 0; i < (int)(k * n); ++i)
        for (int j = 0; j < (int)(k * m); ++j)
            b[i][j] = a[i / (int)k][j / (int)k];
    for (const auto &row : b) {
        for (auto elem : row)
            cout << elem;
        cout << '\n';
    }

    cin.close();
    cout.close();
    return;
}
