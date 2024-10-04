// author: Danila "akshin_" Axyonov

#include <iostream>
using namespace std;
typedef long long int lli;

#define plli                pair<lli, lli>
#define mp(_first, _second) make_pair(_first, _second)
#define pb(_elem)           push_back(_elem)

const lli MAX_SIZE = (lli)1e2 + 5LL;

lli N,
    A[MAX_SIZE];
lli q,
    w;
lli from,
    to;

void solve();

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    solve();
    
    return 0;
}

void solve() {
    cin >> N;
    for (int i = 0; i < (int)N; ++i)
        cin >> A[i];
    cin >> q >> w;
    --q;
    --w;

    from = A[q];
    to = A[w];
    for (int i = 0; i < (int)N; ++i)
        if (A[i] == from)
            A[i] = to;
    
    for (int i = 0; i < (int)N; ++i)
        cout << A[i] << ' ';
    cout << '\n';
    return;
}
