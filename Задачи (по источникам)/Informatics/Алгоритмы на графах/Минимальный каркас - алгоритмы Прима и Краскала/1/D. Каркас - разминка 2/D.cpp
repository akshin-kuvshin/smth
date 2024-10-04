// author: Danila "akshin_" Axyonov

#include <iostream>
using namespace std;
typedef long long int lli;

#define plli                pair<lli, lli>
#define mp(_first, _second) make_pair(_first, _second)
#define pb(_elem)           push_back(_elem)

const lli MAX_SIZE = (lli)1e2 + 5LL,
          INF = (lli)1e3 + 1LL;

lli N,
    G[MAX_SIZE][MAX_SIZE];
bool v[MAX_SIZE];
lli d = INF;
plli ind;

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
        for (int j = 0; j < (int)N; ++j)
            cin >> G[i][j];
    for (int i = 0; i < (int)N; ++i)
        cin >> v[i];
    
    for (int i = 0; i < (int)N; ++i)
        for (int j = 0; j < (int)N; ++j)
            if (v[i] xor v[j])
                if (G[i][j] < d) {
                    d = G[i][j];
                    ind = mp((lli)(i + 1), (lli)(j + 1));
                }
    
    if (!v[ind.first - 1LL])
        cout << ind.first << ' ' << ind.second;
    else
        cout << ind.second << ' ' << ind.first;
    cout << '\n';
    return;
}
