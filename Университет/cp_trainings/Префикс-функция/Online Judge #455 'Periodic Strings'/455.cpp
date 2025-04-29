// author: Danila "akshin_" Axyonov

#include <iostream>
#include <string>
#include <vector>
using namespace std;

#define pb(_elem)           push_back(_elem)

void solve(int q);
vector<int> prefix(const string& S);

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int Q;
    cin >> Q;
    for (int q = 0; q < Q; ++q)
        solve(q);
    
    cout << '\n'; // без этой строчки был WA...
    return 0;
}

void solve(int q) {
    string S;
    cin >> S;

    vector<int> p = prefix(S);
    
    int len = (int)S.size();
    int k = len - p.back();
    if (len % k)
        k = len;
    
    if (q)
        cout << "\n\n";
    cout << k;
    return;
}

vector<int> prefix(const string& S) {
    int len = (int)S.size();
    vector<int> p(len);
    for (int i = 1; i < len; ++i) {
        int k = p[i - 1];
        while (k > 0 and S[k] != S[i])
            k = p[k - 1];
        if (S[k] == S[i])
            ++k;
        p[i] = k;
    }
    return p;
}
