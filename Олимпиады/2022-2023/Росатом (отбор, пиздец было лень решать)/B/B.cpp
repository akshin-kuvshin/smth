// author: Danila "akshin_" Aksionov

#include <iostream>
#include <algorithm>
using namespace std;
typedef long long int lli;

const lli MAX_SIZE = 100000LL;

lli N,
    H,
    A[MAX_SIZE + 5LL],
    L,
    R;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N >> H;
    for (int i = 0; i < (int)N; ++i)
        cin >> A[i];
    
    sort(A, A + N);
    L = upper_bound(A, A + N, H) - A;
    R = N - L;

    cout << L << ' ' << R << '\n';
    return 0;
}
