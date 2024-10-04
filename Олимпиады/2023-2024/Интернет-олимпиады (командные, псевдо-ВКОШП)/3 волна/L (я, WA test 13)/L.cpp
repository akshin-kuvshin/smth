// author: Danila "akshin_" Axyonov
  
#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>
#include <set>
using namespace std;
typedef long long int lli;
  
#define plli                pair<lli, lli>
#define mp(_first, _second) make_pair(_first, _second)
#define pb(_elem)           push_back(_elem)
  
#define in                  first
#define out                 second
  
const lli MAX_SIZE = (lli)2e5 + 5LL;
  
lli N,
    M;
string S[MAX_SIZE];
unordered_map<string, vector<string>> G;
unordered_map<string, plli> deg;
  
// ??????????
class Compare {
public:
    bool operator ()(const string &S1, const string &S2) const {
        return deg[S1].out < deg[S2].out;
    }
};
multiset<string, Compare> SS;
  
lli ans;
  
void solve();
void dfs(string);
  
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
      
    solve();
      
    return 0;
}
  
void solve() {
    cin >> N >> M;
    for (int i = 0; i < (int)N; ++i) {
        cin >> S[i];
        G[S[i]] = vector<string>();
        deg[S[i]] = mp(0LL, 0LL);
    }
    for (int i = 0; i < (int)M; ++i) {
        string from, to;
        cin >> from >> to;
        G[to].pb(from);
        ++deg[from].out;
        ++deg[to].in;
    }
  
    for (int i = 0; i < (int)N; ++i)
        SS.insert(S[i]);
      
    while (!SS.empty()) {
        string str = *SS.begin();
        SS.erase(SS.begin());
  
        dfs(str);
        ++ans;
    }
  
    cout << ans << '\n';
    return;
}
  
void dfs(string str) {
    for (string ns : G[str]) {
        if (SS.find(ns) == SS.end())
            continue;
        SS.erase(ns);
        dfs(ns);
    }
    return;
}
