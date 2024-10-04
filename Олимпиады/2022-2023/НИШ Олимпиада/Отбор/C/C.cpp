#include <iostream>
#include <algorithm>
using namespace std;
typedef long long int lli;

const lli N = 3LL;

lli A[N + 5LL];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    for (int i = 0; i < (int)N; ++i)
        cin >> A[i];
    sort(A, A + N);
    cout << A[N - 1LL] << ' ' << A[N - 2LL] << '\n';
    
    return 0;
}
