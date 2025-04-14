// author: Danila "akshin_" Axyonov

#include <iostream>
#include <string>
#include <vector>
using namespace std;
using lli = long long int;

#define pb(_elem)   push_back(_elem)

vector<lli> prefix(const string&);

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    string T, S;
    getline(cin, T);
    getline(cin, S);
    
    string A = S + "#" + T;
    vector<lli> p = prefix(A);
    
    lli S_len = (lli)S.size(),
        Ap_len = (lli)p.size();
    vector<lli> ans;
    for (int i = (int)S_len + 1; i < (int)Ap_len; ++i)
        if (p[i] == S_len)
            ans.pb((lli)i - 2LL * S_len + 1LL);
    
    cout << ans.size() << '\n';
    for (lli pos : ans)
        cout << pos << ' ';
    cout << '\n';
    return 0;
}

vector<lli> prefix(const string& S) {
    lli len = (lli)S.size();
    vector<lli> p(len);
    p[0] = 0LL;
    for (int i = 1; i < (int)len; ++i) {
        lli k = p[i - 1];
        while (k > 0LL and S[i] != S[k])
            k = p[k - 1LL];
        if (S[i] == S[k])
            ++k;
        p[i] = k;
    }
    return p;
}
