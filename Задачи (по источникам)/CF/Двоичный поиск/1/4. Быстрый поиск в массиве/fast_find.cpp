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

lli find_lower(lli*, lli, lli); // max i: a[i] <= elem
lli find_upper(lli*, lli, lli); // min i: a[i] >= elem

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
        
        if ((left_ind = find_upper(A, N, _left)) == N) {
            cout << 0LL << '\n';
            continue;
        }
        if ((right_ind = find_lower(A, N, _right)) == -1LL) {
            cout << 0 << '\n';
            continue;
        }

        cout << (right_ind - left_ind + 1LL) << '\n';
    }
    
    return 0;
}

lli find_lower(lli *arr, lli sz, lli elem) {
    lli l = -1LL, // a[l] <= elem
        r = sz; // a[r] > elem
    
    while (l + 1LL < r) {
        lli m = (l + r) / 2LL;

        if (arr[m] <= elem)
            l = m;
        else
            r = m;
    }

    return l;
}

lli find_upper(lli *arr, lli sz, lli elem) {
    lli l = -1LL, // a[l] = elem
        r = sz; // a[r] >= elem
    
    while (l + 1LL < r) {
        lli m = (l + r) / 2LL;

        if (arr[m] < elem)
            l = m;
        else
            r = m;
    }

    return r;
}
