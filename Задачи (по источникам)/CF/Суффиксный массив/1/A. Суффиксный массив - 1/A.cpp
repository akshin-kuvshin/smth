// author: Danila "akshin_" Axyonov

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long int lli;

#define plli                pair<lli, lli>
#define mp(_first, _second) make_pair(_first, _second)
#define pb(_elem)           push_back(_elem)

string S;
lli N;
vector<lli> p,
            c;

void solve();

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    solve();
    
    return 0;
}

void solve() {
    cin >> S;
    S += '$';
    N = (lli)S.size();
    p.resize(N);
    c.resize(N);

    {   // k = 0

        vector<pair<char, lli>> A(N);
        for (int i = 0; i < (int)N; ++i)
            A[i] = mp(S[i], (lli)i);
        sort(A.begin(), A.end());

        for (int i = 0; i < (int)N; ++i)
            p[i] = A[i].second;
        c[p[0]] = 0LL;
        for (int i = 1; i < (int)N; ++i)
            if (A[i - 1].first == A[i].first)
                c[p[i]] = c[p[i - 1]];
            else
                c[p[i]] = c[p[i - 1]] + 1;
    }

    int k = 0;
    while ((1LL << k) < N) {
        vector<pair<plli, lli>> A(N);
        for (int i = 0; i < (int)N; ++i)
            A[i] = mp(mp(c[i], c[(i + (1 << k)) % (int)N]), (lli)i);
        sort(A.begin(), A.end());

        for (int i = 0; i < (int)N; ++i)
            p[i] = A[i].second;
        c[p[0]] = 0LL;
        for (int i = 1; i < (int)N; ++i)
            if (A[i - 1].first == A[i].first)
                c[p[i]] = c[p[i - 1]];
            else
                c[p[i]] = c[p[i - 1]] + 1;
        
        ++k;
    }
    
    for (int i = 0; i < (int)N; ++i)
        cout << p[i] << ' ';
    cout << '\n';
    return;
}
