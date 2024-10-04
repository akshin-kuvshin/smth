#include <iostream>
using namespace std;
typedef long long int lli;

const lli MAX_SIZE = 100000LL;

lli N,
    A[MAX_SIZE + 5LL];
lli Q,
    x;

bool find(lli*, lli, lli);

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N >> Q;
    for (int i = 0; i < (int)N; ++i)
        cin >> A[i];
    
    while (Q--) {
        cin >> x;
        if (find(A, N, x))
            cout << "YES\n";
        else
            cout << "NO\n";
    }
    
    return 0;
}

bool find(lli *arr, lli sz, lli elem) {
    lli l = 0LL,
        r = sz - 1LL;
    
    while (l <= r) {
        lli m = (l + r) / 2LL;

        if (arr[m] == elem)
            return true;
        if (arr[m] < elem)
            l = m + 1LL;
        if (elem < arr[m])
            r = m - 1LL;
    }

    return false;
}
