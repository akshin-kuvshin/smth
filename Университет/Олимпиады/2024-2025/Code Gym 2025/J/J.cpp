// author: Danila "akshin_" Axyonov

#include <iostream>
#include <string>
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
    
    lli Q;
    cin >> Q;
    while (Q--)
        solve();
    
    return 0;
}

void solve() {
    lli n,
        m;
    cin >> n >> m;
    string root;
    cin >> root;
    vector<vector<lli>> a(n, vector<lli>(m));
    for (int i = 0; i < (int)n; ++i)
        for (int j = 0; j < (int)m; ++j)
            cin >> a[i][j];
    
    vector<lli> row_sum(n),
                col_sum(m);
    for (int i = 0; i < (int)n; ++i)
        for (int j = 0; j < (int)m; ++j) {
            row_sum[i] += a[i][j];
            col_sum[j] += a[i][j];
        }

    int i = 0,
        j = 0;
    for (char dir : root) {
        if (dir == 'D') {
            a[i][j] = -row_sum[i];
            col_sum[j] += a[i][j];
            ++i;
        } else { // dir == 'R'
            a[i][j] = -col_sum[j];
            row_sum[i] += a[i][j];
            ++j;
        }
    }
    a.back().back() = -row_sum.back();

    for (i = 0; i < (int)n; ++i) {
        for (j = 0; j < (int)m; ++j)
            cout << a[i][j] << ' ';
        cout << '\n';
    }
    
    return;
}
