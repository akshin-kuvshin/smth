// author: Danila "akshin_" Axyonov

#include <iostream>
#include <vector>
using namespace std;
typedef long long int lli;

lli N;
vector<lli> A,
            B;
int best_bit = 32;
lli answer;

void solve();
bool bit(lli, int);

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}

void solve() {
    cin >> N;
    A.resize(N); B.resize(N);
    for (int i = 0; i < (int)N; ++i)
        cin >> A[i];
    for (int i = 0; i < (int)N; ++i) {
        lli f = 1LL;
        int cnt = 0;
        while (f <= A[i]) {
            f <<= 1;
            ++cnt;
        }
        B[i] = f - 1LL - A[i];
        best_bit = min(best_bit, cnt - 1);
    }

    if (best_bit == -1) {
        cout << "0\n";
        return;
    }

    if (bit(A[0], best_bit)) answer = A[0];
    else answer = B[0];
    for (int i = 1; i < (int)N; ++i)
        if (bit(A[i], best_bit)) answer &= A[i];
        else answer &= B[i];

    cout << answer << '\n';
    return;
}

bool bit(lli num, int pos) {
    return (bool)((num >> pos) & 1LL);
}
