#include <iostream>
#include <algorithm>
using namespace std;
typedef long long int lli;

const lli MAX_SIZE = 100000LL;

lli N,
    A[MAX_SIZE + 5LL];
lli Q,
    _left,
    _right,
    left_ind,
    right_ind;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N;
    for (int i = 0; i < (int)N; ++i)
        cin >> A[i];
    sort(A, A + N);
    
    cin >> Q;
    while (Q--) {
        cin >> _left >> _right;
        
        if ((left_ind = lower_bound(A, A + N, _left) - A) == N) {
            cout << 0LL << '\n';
            continue;
        }
        if ((right_ind = upper_bound(A, A + N, _right) - A - 1LL) == -1LL) {
            cout << 0LL << '\n';
            continue;
        }
        
        cout << (right_ind - left_ind + 1LL) << '\n';
    }
    
    return 0;
}
