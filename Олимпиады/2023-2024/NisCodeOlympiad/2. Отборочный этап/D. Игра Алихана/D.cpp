// author: Danila "akshin_" Axyonov

#include <iostream>
using namespace std;
typedef long long int lli;

#define plli                pair<lli, lli>
#define mp(_first, _second) make_pair(_first, _second)
#define pb(_elem)           push_back(_elem)

const lli MAX_SIZE = (lli)1e3 + 5LL;

lli N,
    M,
    A[MAX_SIZE][MAX_SIZE];
lli Q,
    x,
    y;

void solve();
bool check(lli, lli);

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    solve();
    
    return 0;
}

void solve() {
    cin >> N >> M >> Q;
    for (int i = 0; i < (int)Q; ++i) {
        cin >> x >> y;
        A[x][y] = 1LL;
        if (check(x, y)) {
            cout << (i + 1) << '\n';
            return;
        }
    }
    cout << "0\n";
    return;
}

bool check(lli i, lli j) {
    if (A[i - 1LL][j - 1LL] == 1LL and A[i - 1LL][j] == 1LL and A[i][j - 1LL] == 1LL and A[i][j] == 1LL)
        return true;
    if (A[i - 1LL][j] == 1LL and A[i - 1LL][j + 1LL] == 1LL and A[i][j] == 1LL and A[i][j + 1LL] == 1LL)
        return true;
    if (A[i][j - 1LL] == 1LL and A[i][j] == 1LL and A[i + 1LL][j - 1LL] == 1LL and A[i + 1LL][j] == 1LL)
        return true;
    if (A[i][j] == 1LL and A[i][j + 1LL] == 1LL and A[i + 1LL][j] == 1LL and A[i + 1LL][j + 1LL] == 1LL)
        return true;
    return false;
}
