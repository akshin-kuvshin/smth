// author: Danila "akshin_" Axyonov

#include <iostream>
#include <algorithm>
using namespace std;
typedef long long int lli;

#define plli                pair<lli, lli>
#define mp(_first, _second) make_pair(_first, _second)
#define pb(_elem)           push_back(_elem)

const lli MAX_SIZE = 200005LL;

lli Q;
lli N,
    A[MAX_SIZE],
    _sum,
    max_ind;
lli answer;

void solve();
lli bs();
bool f(lli);

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
    _sum = 0LL;
    for (int i = 0; i < (int)N; ++i) {
        cin >> A[i];
        _sum += A[i];
    }
    max_ind = (lli)(max_element(A, A + N) - A);
    
    if (N <= 2LL) {
        cout << "-1\n";
        return;
    }
    
    answer = bs();
    cout << answer << '\n';
    
    return;
}

lli bs() {
    lli l = -1LL,
        r = 1000000000000000001LL;
    while (l + 1LL < r) {
        lli m = (l + r) >> 1;
        if (f(m))
            r = m;
        else // not f(m)
            l = m;
    }
    return r;
}

bool f(lli x) {
    A[max_ind] += x;
    lli cnt = 0LL;
    for (int i = 0; i < (int)N; ++i)
        if (2LL * N * A[i] < _sum + x)
            ++cnt;
    A[max_ind] -= x;
    return (2LL * cnt > N);
}
