#include <iostream>
using namespace std;

typedef long long int lli;

const lli N_max = 1000000LL;

lli N,
    B[N_max + 5LL],
    A[N_max + 5LL];
lli Q,
    l,
    r,
    d;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N;
    for (int i = 0; i < (int)N; ++i)
        cin >> B[i + 1];
    
    cin >> Q;
    while (Q--) {
        cin >> l >> r >> d;

        A[l - 1LL] += d;
        A[r] -= d;
    }

    for (int i = 0; i < (int)N; ++i) {
        A[i + 1] += A[i];
        B[i + 1] += A[i];
        cout << B[i + 1] << ' ';
    }
    cout << '\n';
    
    return 0;
}
