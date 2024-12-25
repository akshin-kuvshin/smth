// author: Danila "akshin_" Axyonov

#include <fstream>
#include <vector>
using namespace std;
typedef long long int lli;

#define plli                pair<lli, lli>
#define mp(_first, _second) make_pair(_first, _second)
#define pb(_elem)           push_back(_elem)

const lli INF = (lli)1e18 + 1LL;

void solve();

int main() {
    ios::sync_with_stdio(false);
    
    solve();
    
    return 0;
}

void solve() {
    ifstream cin;
    cin.open("cbarn.in");
    cin.tie(nullptr);
    ofstream cout;
    cout.open("cbarn.out");

    lli n;
    cin >> n;
    vector<lli> a(n);
    for (int i = 0; i < (int)n; ++i)
        cin >> a[i];
    
    lli ans = INF;
    for (int i = 0; i < (int)n; ++i) {
        lli cur = 0LL,
            k = 1LL;
        for (int j = (i + 1) % (int)n; j != i; j = (j + 1) % (int)n)
            cur += a[j] * k++;
        ans = min(ans, cur);
    }
    cout << ans << '\n';

    cin.close();
    cout.close();
    return;
}
