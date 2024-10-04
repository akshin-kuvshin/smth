// author: Danila "akshin_" Aksionov

#include <iostream>
using namespace std;
typedef long long int lli;

#define pb(elem) push_back(elem)
#define mp(_first, _second) make_pair(_first, _second)
#define sz(object) (lli)(object).size()
#define all(object) (object).begin(), (object).end()

const lli MAX_SIZE = 1000LL;

lli N,
    M,
    A[MAX_SIZE + 5LL][MAX_SIZE + 5LL],
    d[MAX_SIZE + 5LL][MAX_SIZE + 5LL];
lli Q,
    lx,
    ly,
    rx,
    ry,
    adding;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin >> N >> M;
    for (int i = 1; i <= (int)N; ++i)
        for (int j = 1; j <= (int)M; ++j)
            cin >> A[i][j];
    
    for (int i = 0; i < (int)N; ++i)
        for (int j = 0; j < (int)M; ++j)
            d[i][j] = A[i + 1][j + 1] - A[i + 1][j] - A[i][j + 1] + A[i][j];
    
    cin >> Q;
    while (Q--) {
        cin >> lx >> ly >> rx >> ry >> adding;
        --lx, --ly;

        d[lx][ly] += adding;
        d[lx][ry] -= adding;
        d[rx][ly] -= adding;
        d[rx][ry] += adding;
    }

    for (int i = 0; i < (int)N; ++i)
        for (int j = 0; j < (int)M; ++j)
            A[i + 1][j + 1] = A[i + 1][j] + A[i][j + 1] - A[i][j] + d[i][j];
    
    for (int i = 1; i <= (int)N; ++i) {
        for (int j = 1; j <= (int)M; ++j)
            cout << A[i][j] << ' ';
        cout << '\n';
    }

    return 0;
}
