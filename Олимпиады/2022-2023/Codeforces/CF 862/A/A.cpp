#include <iostream>
#define NO_ANSWER -1LL
using namespace std;
typedef long long int lli;

const lli MAX_SIZE = 1000LL;

lli Q;
lli N,
    A[MAX_SIZE + 5LL];
lli B[MAX_SIZE + 5LL];

void solve();

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> Q;
    while (Q--) {
        solve();
    }
    
    return 0;
}

void solve() {
    cin >> N;
    for (int i = 0; i < (int)N; ++i)
        cin >> A[i];
    
    for (lli x = 0LL; x < 256LL; ++x) {
        for (int i = 0; i < (int)N; ++i)
            B[i] = A[i] ^ x;
        
        lli xor_sum = B[0];
        for (int i = 1; i < (int)N; ++i)
            xor_sum ^= B[i];
        
        if (xor_sum == 0LL) {
            cout << x << '\n';
            return;
        }
    }

    cout << NO_ANSWER << '\n';
    return;
}
