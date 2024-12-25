// author: Danila "akshin_" Axyonov

#include <fstream>
#include <string>
#include <vector>
#include <map>
using namespace std;
typedef long long int lli;

#define plli                pair<lli, lli>
#define mp(_first, _second) make_pair(_first, _second)
#define pb(_elem)           push_back(_elem)

void solve();
lli count(const string&, char);

int main() {
    ios::sync_with_stdio(false);
    
    solve();
    
    return 0;
}

void solve() {
    ifstream cin;
    cin.open("blocks.in");
    cin.tie(nullptr);
    ofstream cout;
    cout.open("blocks.out");

    int n;
    cin >> n;
    vector<pair<string, string>> a(n);
    for (int i = 0; i < (int)n; ++i)
        cin >> a[i].first >> a[i].second;
    
    map<char, lli> m;
    for (auto [S1, S2] : a)
        for (char c = 'a'; c <= 'z'; ++c)
            m[c] += max(count(S1, c), count(S2, c));
    for (auto [_, cnt] : m)
        cout << cnt << '\n';
    
    cin.close();
    cout.close();
    return;
}

lli count(const string &S, char c) {
    lli res = 0LL;
    for (auto cc : S)
        res += (c == cc);
    return res;
}
