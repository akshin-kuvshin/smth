// author: Danila "akshin_" Axyonov

#include <iostream>
#include <string>
#include <vector>
using namespace std;
typedef long long int lli;

#define plli                pair<lli, lli>
#define mp(_first, _second) make_pair(_first, _second)
#define pb(_elem)           push_back(_elem)

const int INF = (int)1e9 + 1;

lli Q;
string S;
vector<pair<char, int>> little,
                        big;

void solve();

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin >> Q;
    while (Q--)
        solve();
    
    return 0;
}

void solve() {
    cin >> S;
    int sz = (int)S.size();

    little.clear();
    big.clear();
    for (int i = 0; i < sz; ++i) {
        char c = S[i];

        if (c == 'b') {
            if (!little.empty())
                little.pop_back();
        } else if (c == 'B') {
            if (!big.empty())
                big.pop_back();
        } else if ('a' <= c and c <= 'z')
            little.pb(mp(c, i));
        else // 'A' <= c and c <= 'Z'
            big.pb(mp(c, i));
    }

    little.pb(mp('\0', INF));
    big.pb(mp('\0', INF));

    int i = 0,
        j = 0;
    while (i + 1 < (int)little.size() or j + 1 < (int)big.size()) {
        if (little[i].second < big[j].second)
            cout << little[i++].first;
        else
            cout << big[j++].first;
    }
    cout << '\n';
    
    return;
}
