// author: Danila "akshin_" Aksionov

#include <iostream>
#include <algorithm>
using namespace std;
typedef long long int lli;

#define plli                pair<lli, lli>
#define mp(_first, _second) make_pair(_first, _second)
#define pb(_elem)           push_back(_elem)

const lli MAX_SIZE = (lli)4e3 + 5LL;

lli N,
    A[MAX_SIZE];
lli ans;

void solve();

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    solve();
    
    return 0;
}

void solve() {
    cin >> N;
    for (int i = 0; i < (int)N; ++i)
        cin >> A[i];
    sort(A, A + N);

    for (int i = 0; i < (int)N; ++i)
        for (int j = i + 1; j < (int)N; ++j)
            ans += lower_bound(A + j + 1, A + N, A[i] + A[j]) - (A + j + 1);
    
    cout << ans << '\n';
    return;
}
