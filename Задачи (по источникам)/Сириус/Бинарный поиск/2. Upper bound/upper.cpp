// author: Danila "akshin_" Aksionov

#include <iostream>
#include <algorithm>
using namespace std;
typedef long long int lli;

#define plli                pair<lli, lli>
#define mp(_first, _second) make_pair(_first, _second)
#define pb(_elem)           push_back(_elem)

const lli MAX_SIZE = (lli)2.5e5 + 5LL;

lli N,
    A[MAX_SIZE];
lli M,
    q[MAX_SIZE];

void solve();
lli _upper(lli*, lli, lli);

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    solve();
    
    return 0;
}

void solve() {
    // input
    cin >> N;
    for (int i = 0; i < (int)N; ++i)
        cin >> A[i];
    cin >> M;
    for (int i = 0; i < (int)M; ++i)
        cin >> q[i];
    
    // solution
    sort(A, A + N);
    for (int i = 0; i < (int)M; ++i)
        cout << _upper(A, N, q[i]) << ' ';
    cout << '\n';
    
    return;
}

lli _upper(lli *arr, lli sz, lli elem) {
    lli l = -1LL,
        r = sz;
    while (l + 1LL < r) {
        lli mid = (l + r) >> 1;
        if (arr[mid] <= elem)
            l = mid;
        else
            r = mid;
    }
    return r;
}
