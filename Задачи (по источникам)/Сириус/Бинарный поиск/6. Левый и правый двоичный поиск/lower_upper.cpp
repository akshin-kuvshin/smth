// author: Danila "akshin_" Aksionov

#include <iostream>
#include <algorithm>
using namespace std;
typedef long long int lli;

#define plli                pair<lli, lli>
#define mp(_first, _second) make_pair(_first, _second)
#define pb(_elem)           push_back(_elem)

const lli MAX_SIZE = (lli)2e4 + 5LL;

lli N,
    A[MAX_SIZE];
lli M,
    B[MAX_SIZE];

void solve();

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    solve();
    
    return 0;
}

void solve() {
    cin >> N >> M;
    for (int i = 0; i < (int)N; ++i)
        cin >> A[i];
    for (int i = 0; i < (int)M; ++i)
        cin >> B[i];
    
    for (int i = 0; i < (int)M; ++i) {
        lli l = lower_bound(A, A + N, B[i]) - A,
            r = upper_bound(A, A + N, B[i]) - A;
        if (r - l == 0LL)
            cout << "0\n";
        else
            cout << (l + 1LL) << ' ' << r << '\n';
    }
        
    return;
}
