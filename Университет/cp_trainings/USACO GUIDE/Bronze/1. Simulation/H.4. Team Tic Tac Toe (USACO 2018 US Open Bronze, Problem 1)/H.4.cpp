// author: Danila "akshin_" Axyonov

#include <fstream>
#include <vector>
#include <set>
using namespace std;
typedef long long int lli;

#define plli                pair<lli, lli>
#define mp(_first, _second) make_pair(_first, _second)
#define pb(_elem)           push_back(_elem)

const lli n = 3LL;

void solve();

int main() {
    ios::sync_with_stdio(false);
    
    solve();
    
    return 0;
}

void solve() {
    ifstream cin;
    cin.open("tttt.in");
    cin.tie(nullptr);
    ofstream cout;
    cout.open("tttt.out");

    vector<vector<char>> a(n, vector<char>(n));
    for (auto &row : a)
        for (auto &c : row)
            cin >> c;
    
    set<char> solo;
    set<pair<char, char>> duo;
    set<char> S;
    for (int i = 0; i < (int)n; ++i) {
        S.clear();
        for (int j = 0; j < (int)n; ++j)
            S.insert(a[i][j]);
        if ((lli)S.size() == 1LL) solo.insert(*S.begin());
        else if ((lli)S.size() == 2LL) duo.insert(mp(*S.begin(), *(++S.begin())));

        S.clear();
        for (int j = 0; j < (int)n; ++j)
            S.insert(a[j][i]);
        if ((lli)S.size() == 1LL) solo.insert(*S.begin());
        else if ((lli)S.size() == 2LL) duo.insert(mp(*S.begin(), *(++S.begin())));
    }
    S.clear();
    for (int i = 0; i < (int)n; ++i)
        S.insert(a[i][i]);
    if ((lli)S.size() == 1LL) solo.insert(*S.begin());
    else if ((lli)S.size() == 2LL) duo.insert(mp(*S.begin(), *(++S.begin())));
    S.clear();
    for (int i = 0; i < (int)n; ++i)
        S.insert(a[i][(int)n - i - 1]);
    if ((lli)S.size() == 1LL) solo.insert(*S.begin());
    else if ((lli)S.size() == 2LL) duo.insert(mp(*S.begin(), *(++S.begin())));

    cout << (lli)solo.size() << '\n' << (lli)duo.size() << '\n';
    cin.close();
    cout.close();
    return;
}
