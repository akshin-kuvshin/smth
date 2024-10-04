// author: Danila "akshin_" Aksionov

#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
typedef long long int lli;

#define plli                pair<lli, lli>
#define mp(_first, _second) make_pair(_first, _second)
#define pb(_elem)           push_back(_elem)

const lli MAX_SIZE = (lli)1e5 + 5LL;
const string ans[2] = {"NO\n", "YES\n"};

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
    
    for (int i = 0; i < (int)M; ++i)
        cout << ans[binary_search(A, A + N, B[i])];
        
    return;
}
