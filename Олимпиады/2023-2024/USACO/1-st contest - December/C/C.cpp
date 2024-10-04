// author: Danila "akshin_" Axyonov

#include <iostream>
#include <map>
#include <string>
#include <unordered_map>
using namespace std;
typedef long long int lli;

#define plli                pair<lli, lli>
#define mp(_first, _second) make_pair(_first, _second)
#define pb(_elem)           push_back(_elem)

lli T,
    C;
map<lli, bool> A;
string S;
lli answer;

void solve();
lli count(const string&);

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    solve();
    
    return 0;
}

void solve() {
    cin >> T >> C;
    while (T--) {
        lli ind;
        cin >> ind;
        A[ind] = true;
    }
    cin >> S;
    
    for (char &_c : S) {
        char base = _c;

        _c = 'F';
        answer = max(answer, count(S));
        _c = 'L';
        answer = max(answer, count(S));
        _c = 'R';
        answer = max(answer, count(S));

        _c = base;
    }
    
    cout << answer << '\n';
    return;
}

lli count(const string &cmd) {
    unordered_map<lli, bool> used;
    lli ans = 0LL;

    lli pos = 0LL;
    for (char _c : cmd) {
        if (_c == 'L')
            --pos;
        else if (_c == 'R')
            ++pos;
        else { // _c == 'F'
            if (used[pos])
                continue;
            used[pos] = true;
            
            if (A[pos])
                ++ans;
        }
    }

    return ans;
}
