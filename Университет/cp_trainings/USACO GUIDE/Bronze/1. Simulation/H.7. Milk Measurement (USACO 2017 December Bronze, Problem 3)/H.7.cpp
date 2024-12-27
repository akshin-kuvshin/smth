// author: Danila "akshin_" Axyonov

#include <fstream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;
typedef long long int lli;

#define plli                pair<lli, lli>
#define mp(_first, _second) make_pair(_first, _second)
#define pb(_elem)           push_back(_elem)

void solve();
vector<string> get_maxs(const map<string, lli>&);

int main() {
    ios::sync_with_stdio(false);
    
    solve();
    
    return 0;
}

void solve() {
    ifstream cin;
    cin.open("measurement.in");
    cin.tie(nullptr);
    ofstream cout;
    cout.open("measurement.out");

    size_t n;
    cin >> n;
    vector<tuple<lli, string, string>> a(n);
    for (size_t i = 0ULL; i < n; ++i)
        cin >> get<0>(a[i]) >> get<1>(a[i]) >> get<2>(a[i]);
    sort(a.begin(), a.end());
    
    map<string, lli> cnt = {
        {"Bessie", 7LL},
        {"Elsie", 7LL},
        {"Mildred", 7LL}
    };

    vector<string> maxs = {"Bessie", "Elsie", "Mildred"};
    size_t ans = 0ULL;
    for (auto [_, name, op] : a) {
        lli num = stoll(op);
        cnt[name] += num;
        vector<string> new_maxs = get_maxs(cnt);
        if (maxs != new_maxs) {
            maxs = new_maxs;
            ++ans;
        }
    }
    cout << ans << '\n';

    cin.close();
    cout.close();
    return;
}

vector<string> get_maxs(const map<string, lli> &cnt) {
    lli _max = cnt.at("Bessie");
    for (auto [_, val] : cnt)
        _max = max(_max, val);
    
    vector<string> res;
    for (auto [name, val] : cnt)
        if (val == _max)
            res.pb(name);
    return res;
}
