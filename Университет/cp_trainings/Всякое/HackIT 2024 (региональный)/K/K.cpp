// author: Danila "akshin_" Axyonov

#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
using namespace std;
using lli = long long int;

#define plli                pair<lli, lli>
#define mp(_first, _second) make_pair(_first, _second)
#define pb(_elem)           push_back(_elem)

vector<lli> prefix(const string& S);

void solve();

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    solve();
    
    return 0;
}

void solve() {
    unordered_map<char, char> next;
    next['0'] = '1';
    next['1'] = '0';

    lli n;
    cin >> n;
    string S;
    cin >> S;

    string from_zero,
           from_one;
    from_zero.pb('0');
    from_one.pb('1');
    for (int _ = 1; _ < (int)n; ++_) {
        from_zero.pb(next[from_zero.back()]);
        from_one.pb(next[from_one.back()]);
    }

    string S1 = from_zero + '#' + S,
           S2 = from_one + '#' + S;
    vector<lli> p1 = prefix(S1),
                p2 = prefix(S2);

    lli ans = 0LL;
    for (int i = (int)n + 1; i < 2 * (int)n + 1; ++i) {
        ans = max(ans, p1[i]);
        ans = max(ans, p2[i]);
    }
    cout << ans << '\n';
    return;
}

vector<lli> prefix(const string& S) {
    lli len = (lli)S.size();
    vector<lli> p(len);
    for (int i = 1; i < (int)len; ++i) {
        lli k = p[i - 1];
        while (k and S[k] != S[i])
            k = p[k - 1LL];
        if (S[k] == S[i])
            ++k;
        p[i] = k;
    }
    return p;
}
