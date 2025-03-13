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
    ifstream cin("circlecross.in");
    cin.tie(nullptr);
    ofstream cout("circlecross.out");

    string S;
    cin >> S;

    unordered_map<char, vector<lli>> m;
    for (int i = 0; i < (int)S.size(); ++i)
        m[S[i]].pb((lli)i);
    
    lli ans = 0LL;
    for (char c1 = 'A'; c1 <= 'Z'; ++c1)
        for (char c2 = c1 + 1; c2 <= 'Z'; ++c2)
            if (
                (m[c1][0] < m[c2][0] and m[c2][0] < m[c1][1] and m[c1][1] < m[c2][1]) or
                (m[c2][0] < m[c1][0] and m[c1][0] < m[c2][1] and m[c2][1] < m[c1][1])
            ) ++ans;
    cout << ans << '\n';

    cin.close();
    cout.close();
    return;
}
