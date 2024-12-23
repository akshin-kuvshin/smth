// author: Danila "akshin_" Axyonov

#include <fstream>
#include <vector>
#include <algorithm>
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
    cin.open("blist.in");
    cin.tie(nullptr);
    ofstream cout;
    cout.open("blist.out");

    lli n;
    cin >> n;
    vector<lli> s(n),
                t(n),
                b(n);
    for (int i = 0; i < (int)n; ++i)
        cin >> s[i] >> t[i] >> b[i];
    
    vector<plli> q;
    for (int i = 0; i < (int)n; ++i) {
        q.pb(mp(s[i], b[i]));
        q.pb(mp(t[i], -b[i]));
    }
    sort(q.begin(), q.end());

    lli cur = 0LL,
        _max = 0LL;
    for (auto [_, val] : q) {
        cur += val;
        _max = max(_max, cur);
    }
    cout << _max << '\n';

    cin.close();
    cout.close();
    return;
}
