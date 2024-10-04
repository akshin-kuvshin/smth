// author: Danila "akshin_" Aksionov

#include <iostream>
#include <algorithm>
using namespace std;
typedef long long int lli;

const lli MAX_SIZE = (lli)1e5;

lli N,
    A[MAX_SIZE + 5LL];
lli odd[MAX_SIZE + 5LL],
    odd_top,
    even[MAX_SIZE + 5LL],
    even_top;

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

    for (int i = 0; i < (int)N; ++i) {
        if (i <= N / 2LL)
            odd[odd_top++] = A[i];
        else
            even[even_top++] = A[i];
    }

    odd_top = even_top = 0LL;
    for (int i = 0; i < (int)N; ++i) {
        if ((i + 1) & 1)
            A[i] = odd[odd_top++];
        else
            A[i] = even[even_top++];
    }

    for (int i = 1; i < (int)N; i += 2)
        if (!(A[i - 1] < A[i] and A[i] > A[i + 1])) {
            cout << "NO\n";
            return;
        }
    cout << "YES\n";
    return;
}
