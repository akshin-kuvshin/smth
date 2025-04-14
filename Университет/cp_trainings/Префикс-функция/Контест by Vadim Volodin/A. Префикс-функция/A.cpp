// author: Danila "akshin_" Axyonov

#include <iostream>
#include <string>
#include <vector>
using namespace std;
using lli = long long int;

vector<lli> prefix(const string&);

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    string S;
    getline(cin, S);

    vector<lli> p = prefix(S);
    
    lli _sum = 0LL;
    for (lli pi : p)
        _sum += pi;
    cout << _sum << '\n';
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
