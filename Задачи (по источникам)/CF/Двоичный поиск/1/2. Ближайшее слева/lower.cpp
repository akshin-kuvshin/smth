#include <iostream>
using namespace std;
typedef long long int lli;

const lli MAX_SIZE = 100000LL;

lli N,
    A[MAX_SIZE + 5LL];
lli Q,
    x;

lli find_lower(lli*, lli, lli);

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N >> Q;
    for (int i = 0; i < (int)N; ++i)
        cin >> A[i];
    
    while (Q--) {
        cin >> x;
        cout << (find_lower(A, N, x) + 1LL) << '\n';
    }
    
    return 0;
}

lli find_lower(lli *arr, lli sz, lli elem) {
    lli l = -1LL, // arr[l] <= elem
        r = sz; // elem < arr[r]
    
    while (l + 1LL < r) {
        lli m = (l + r) / 2LL;

        if (arr[m] <= elem)
            l = m;
        else
            r = m;
    }

    return l;
}
