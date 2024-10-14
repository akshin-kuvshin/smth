// author: Danila "akshin_" Axyonov

#include <iostream>
using namespace std;
typedef long long int lli;

#define plli                pair<lli, lli>
#define mp(_first, _second) make_pair(_first, _second)
#define pb(_elem)           push_back(_elem)

const lli MAX_SIZE = (lli)1e5 + 5LL,
          MOD = (lli)1e9 + 7LL;

lli POW2[MAX_SIZE];
lli Q,
    N[MAX_SIZE], // useless
    K[MAX_SIZE];

void solve();

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    solve();
    
    return 0;
}

void solve() {
    POW2[0] = 1LL;
    for (int i = 1; i < (int)MAX_SIZE; ++i)
        POW2[i] = (POW2[i - 1] * 2LL) % MOD;
    
    cin >> Q;
    for (int i = 0; i < (int)Q; ++i)
        cin >> N[i];
    for (int i = 0; i < (int)Q; ++i)
        cin >> K[i];
    
    for (int i = 0; i < (int)Q; ++i)
        cout << POW2[K[i]] << '\n';
    
    return;
}
