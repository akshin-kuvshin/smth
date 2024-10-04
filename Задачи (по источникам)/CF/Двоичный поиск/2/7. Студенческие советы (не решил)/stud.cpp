#include <iostream>
#include <algorithm>
using namespace std;
typedef long long int lli;

const lli MAX_SIZE = 50LL;

lli K,
    N,
    A[MAX_SIZE + 5LL],
    _sum;
lli B[MAX_SIZE + 5LL];
lli answer;

bool f(lli);
lli bs();

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> K >> N;
    for (int i = 0; i < (int)N; ++i) {
        cin >> A[i];
        _sum += A[i];
    }
    
    answer = bs();
    cout << answer << '\n';    
    return 0;
}

// Слишком долго проверяет!!!
bool f(lli x) {
    for (int i = 0; i < (int)N; ++i)
        B[i] = A[i];

    lli _min;
    while (x) {
        sort(B, B + N, greater<lli>());
        if (K != N) {
            _min = min(x, B[K - 1LL] - B[K] + 1LL);
        } else {
            _min = min(x, B[K - 1LL]);
        }

        if (_min == 0LL) {
            return false;
        }

        for (int i = 0; i < (int)K; ++i)
            B[i] -= _min;
        x -= _min;
    }

    return true;
}

lli bs() {
    lli l = 0LL,
        r = _sum / K + 1LL;
    
    while (l + 1LL < r) {
        lli m = (l + r) / 2LL;

        if (f(m))
            l = m;
        else
            r = m;
    }

    return l;
}
