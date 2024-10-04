// author: Danila "akshin_" Axyonov

#include <iostream>
using namespace std;
typedef long long int lli;

#define plli                pair<lli, lli>
#define mp(_first, _second) make_pair(_first, _second)
#define pb(_elem)           push_back(_elem)

const lli MAX_SIZE = (lli)1e5 + 5LL,
          INF = (lli)1e18 + 1LL;

lli N,
    A[MAX_SIZE],
    M,
    B[MAX_SIZE];
lli C[MAX_SIZE];

void solve();

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    solve();
    
    return 0;
}

void solve() {
    cin >> N >> M;
    for (int i = 0; i < (int)N; ++i)
        cin >> A[i];
    A[N] = INF;
    for (int j = 0; j < (int)M; ++j)
        cin >> B[j];
    B[M] = INF;
    
    int f = 0,
        s = 0;
    while (f < (int)N or s < (int)M)
        if (A[f] < B[s]) {
            C[f + s] = A[f];
            ++f;
        } else {
            C[f + s] = B[s];
            ++s;
        }
    
    for (int i = 0; i < (int)(N + M); ++i)
        cout << C[i] << ' ';
    cout << '\n';
    return;
}
