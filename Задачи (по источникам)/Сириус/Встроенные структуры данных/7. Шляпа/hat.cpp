// author: Danila "akshin_" Axyonov

#include <iostream>
#include <unordered_map>
#include <string>
using namespace std;
typedef long long int lli;

#define plli                pair<lli, lli>
#define mp(_first, _second) make_pair(_first, _second)
#define pb(_elem)           push_back(_elem)

const lli MAX_SIZE = (lli)1e5 + 5LL;

lli N,
    ans[MAX_SIZE];
lli Q;
unordered_map<string, lli> m;

void solve();

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    solve();
    
    return 0;
}

void solve() {
    cin >> N >> Q;
    while (Q--) {
        lli team;
        string word;
        cin >> team >> word;
        m[word] = team;
    }

    for (pair<string, lli> p : m)
        ++ans[p.second];
    
    for (int i = 1; i <= (int)N; ++i)
        cout << ans[i] << ' ';
    cout << '\n';
    
    return;
}
