// author: Danila "akshin_" Axyonov

#include <fstream>
#include <vector>
#include <algorithm>
using namespace std;
using lli = long long int;

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
    ifstream cin("balancing.in");
    cin.tie(nullptr);
    ofstream cout("balancing.out");

    lli n,
        b;
    cin >> n >> b;
    vector<plli> a(n);
    for (auto& p : a)
        cin >> p.first >> p.second;
    
    vector<lli> xs,
                ys;
    for (auto p : a) {
        xs.push_back(p.first - 1LL);
        xs.push_back(p.first + 1LL);
        ys.push_back(p.second - 1LL);
        ys.push_back(p.second + 1LL);
    }

    lli ans = INF;
    for (auto x : xs) for (auto y : ys) {
        vector<lli> cnt(4);
        for (auto p : a)
            if (p.first < x and p.second < y)
                ++cnt[0];
            else if (p.first < x and p.second > y)
                ++cnt[1];
            else if (p.first > x and p.second < y)
                ++cnt[2];
            else // p.first > x and p.second > y
                ++cnt[3];
        ans = min(ans, *max_element(cnt.begin(), cnt.end()));
    }
    cout << ans << '\n';
    
    cin.close();
    cout.close();
    return;
}
