#include <iostream>
using namespace std;
typedef long long int lli;

const lli MAX_SIZE = 100000LL;

lli N,
    K,
    A[MAX_SIZE + 5LL],
    _sum;
lli answer;

bool f(lli);
lli bs();

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N >> K;
    for (int i = 0; i < (int)N; ++i) {
        cin >> A[i];
        _sum += A[i];
    }
    
    answer = bs();
    cout << answer << '\n';
    
    return 0;
}

bool f(lli x) {
    lli _K = 0LL,
        cur_sum = 0LL;
    
    for (int i = 0; i < (int)N; ++i) {
        if (x < A[i]) return false;

        cur_sum += A[i];
        if (cur_sum > x) {
            ++_K;
            cur_sum = A[i];
        }
    }
    ++_K;

    return (_K <= K);
}

lli bs() {
    lli l = 0LL,
        r = _sum;
    
    while (l + 1LL < r) {
        lli mid = (l + r) / 2LL;

        if (f(mid))
            r = mid;
        else
            l = mid;
    }

    return r;
}
