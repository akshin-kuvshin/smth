// author: Danila "akshin_" Axyonov

#include <iostream>
#include <unordered_map>
#include <string>
#include <map>
using namespace std;
typedef long long int lli;

#define plli                pair<lli, lli>
#define mp(_first, _second) make_pair(_first, _second)
#define pb(_elem)           push_back(_elem)

#define UNDEFINED           -1LL

lli N;
unordered_map<string, string> prim;
map<string, lli> level;

void solve();
lli count_level(const string&);

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    solve();
    
    return 0;
}

void solve() {
    cin >> N;
    while (--N) {
        string son,
               father;
        cin >> son >> father;
        prim[son] = father;

        level[son] = level[father] = UNDEFINED;
    }

    for (auto &p : level) {
        count_level(p.first);
        cout << p.first << ' ' << p.second << '\n';
    }

    return;
}

lli count_level(const string &name) {
    if (level[name] != UNDEFINED)
        return level[name];
    if (prim[name].empty())
        return level[name] = 0LL;
    return level[name] = count_level(prim[name]) + 1LL;
}
