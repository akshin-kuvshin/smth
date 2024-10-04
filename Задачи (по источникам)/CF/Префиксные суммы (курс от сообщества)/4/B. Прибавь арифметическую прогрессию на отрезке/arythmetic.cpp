#include <iostream>
using namespace std;

typedef long long int lli;

const lli N_max = 1000000LL;

lli N,
    A[N_max + 5LL],
    B[N_max + 5LL],
    C[N_max + 5LL];
lli Q,
    l,
    r,
    d;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N;
    for (int i = 0; i < (int)N; ++i) {
        cin >> A[i + 2];
        B[i + 1] = A[i + 2] - A[i + 1];
        C[i] = B[i + 1] - B[i];
    }

    cin >> Q;
    while (Q--) {
        cin >> l >> r >> d;
        ++l, ++r;

        C[l - 2LL] += d;
        C[r - 1LL] -= (r - l + 2LL) * d;
        C[r] += (r - l + 1LL) * d;
    }

    for (int i = 0; i < (int)N; ++i) {
        B[i + 1] = B[i] + C[i];
        A[i + 2] = A[i + 1] + B[i + 1];
        cout << A[i + 2] << ' ';
    }
    cout << '\n';
    
    return 0;
}
