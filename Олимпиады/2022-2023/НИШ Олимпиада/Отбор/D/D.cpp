#include <iostream>
using namespace std;
typedef long long int lli;

lli N,
    K;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N;

    K = N / 10000000LL;
    for (int i = 0; i < 7; ++i) {
        K = K * 10LL + N % 10LL;
        N /= 10LL;
    }

    cout << K << '\n';    
    return 0;
}
