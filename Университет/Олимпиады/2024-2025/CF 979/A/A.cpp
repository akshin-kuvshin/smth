// author: Danila "akshin_" Axyonov

#include <iostream>
#include <algorithm>
using namespace std;
typedef long long int lli;

#define plli                pair<lli, lli>
#define mp(_first, _second) make_pair(_first, _second)
#define pb(_elem)           push_back(_elem)

const lli MAX_SIZE = (lli)1e3 + 5LL;

lli Q;
lli N,
    A[MAX_SIZE],
    _min,
    _max;
lli max_score;

void solve();

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin >> Q;
    while (Q--)
        solve();
    
    return 0;
}

void solve() {
    cin >> N;
    for (int i = 0; i < (int)N; ++i)
        cin >> A[i];
    
    _min = A[min_element(A, A + N) - A];
    _max = A[max_element(A, A + N) - A];

    max_score = (_max - _min) * (N - 1LL);
    cout << max_score << '\n';
    
    return;
}
