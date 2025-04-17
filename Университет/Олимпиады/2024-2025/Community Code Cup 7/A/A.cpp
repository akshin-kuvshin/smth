// author: Danila "akshin_" Axyonov

#include <iostream>
#include <string>
#include <unordered_set>
using namespace std;
using lli = long long int;

#define plli                pair<lli, lli>
#define mp(_first, _second) make_pair(_first, _second)
#define pb(_elem)           push_back(_elem)

void solve();

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    solve();
    
    return 0;
}

void solve() {
    lli n;
    cin >> n;

    unordered_set<char> was;
    while (n--) {
        string s;
        cin >> s;
        for (char c : s)
            was.insert(c);
    }

    bool s = (was.contains('s') or was.contains('S')),
         w = (was.contains('w') or was.contains('W')),
         o = (was.contains('o') or was.contains('O')),
         t = (was.contains('t') or was.contains('T'));
    bool is_swot = s and w and o and t;

    cout << (is_swot ? "YES" : "NO") << '\n';    
    return;
}
