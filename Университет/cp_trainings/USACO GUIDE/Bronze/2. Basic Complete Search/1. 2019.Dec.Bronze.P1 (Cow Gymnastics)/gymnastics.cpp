// author: Danila "akshin_" Axyonov

#include <fstream>
#include <vector>
#include <algorithm>
using namespace std;
using lli = long long int;

#define plli                pair<lli, lli>
#define mp(_first, _second) make_pair(_first, _second)
#define pb(_elem)           push_back(_elem)

void solve();
lli ind(lli, const vector<lli>&);

int main() {
    ios::sync_with_stdio(false);
    
    solve();
    
    return 0;
}

void solve() {
    ifstream cin("gymnastics.in");
    cin.tie(nullptr);
    ofstream cout("gymnastics.out");

    lli k,
        n;
    cin >> k >> n;
    vector<vector<lli>> a(k, vector<lli>(n));
    for (int i = 0; i < (int)k; ++i)
        for (int j = 0; j < (int)n; ++j)
            cin >> a[i][j];
    
    lli ans = 0LL;
    for (lli i = 1LL; i <= n; ++i)
        for (lli j = 1LL; j <= n; ++j) {
            bool flag = true;
            for (int _k = 0; _k < (int)k; ++_k)
                if (ind(i, a[_k]) >= ind(j, a[_k])) {
                    flag = false;
                    break;
                }
            ans += flag;
        }
    
    cout << ans << '\n';

    cin.close();
    cout.close();
    return;
}

lli ind(lli i, const vector<lli>& v) {
    return (lli)(find(v.begin(), v.end(), i) - v.begin());
}
