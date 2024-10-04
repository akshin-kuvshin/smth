// author: Danila "akshin_" Aksionov

#include <iostream>
#include <string>
#include <set>
#include <unordered_map>
using namespace std;
typedef long long int lli;

#define plli                pair<lli, lli>
#define mp(_first, _second) make_pair(_first, _second)
#define pb(_elem)           push_back(_elem)

#define UNDEFINED           -1
#define name                first
#define ext                 second

const lli MAX_SIZE = (lli)1e5 + 5LL;

lli N;
string A[MAX_SIZE];
pair<string, string> p[MAX_SIZE]; // распарсил строки
set<string> ans;
unordered_map<string, lli> m;

void solve();

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    solve();
    
    return 0;
}

void solve() {
    cin >> N;
    for (int i = 0; i < (int)N; ++i) {
        cin >> A[i];
        
        int dot_ind = UNDEFINED,
            sz = (int)A[i].size();
        for (int j = 0; j < sz; ++j)
            if (A[i][j] == '.') {
                dot_ind = j;
                break;
            }
        
        if (dot_ind != UNDEFINED)
            p[i] = mp(A[i].substr(0, dot_ind), A[i].substr(dot_ind + 1LL, sz));
        else
            p[i] = mp(A[i], "");
    }

    for (int i = 0; i < (int)N; ++i) {
        lli ind = m[A[i]];
        ++m[A[i]];

        if (ind == 0LL)
            ans.insert(A[i]);
        else { // ind != 0LL
            if (p[i].ext.size())
                ans.insert(p[i].name + "(" + to_string(ind) + ")." + p[i].ext);
            else // p[i].ext.size() == 0
                ans.insert(A[i] + "(" + to_string(ind) + ")");
        }
    }

    for (string s : ans)
        cout << s << '\n';
    return;
}
