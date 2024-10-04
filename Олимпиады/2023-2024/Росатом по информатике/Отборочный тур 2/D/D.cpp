// author: Danila "akshin_" Axyonov

#include <iostream>
using namespace std;
typedef long long int lli;

#define plli                pair<lli, lli>
#define mp(_first, _second) make_pair(_first, _second)
#define pb(_elem)           push_back(_elem)

const lli MAX_SIZE = (lli)1e5 + 5LL;

lli N,
    A[MAX_SIZE],
    d0[MAX_SIZE],
    d20[MAX_SIZE],
    d020[MAX_SIZE],
    d4020[MAX_SIZE];

void solve();

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    solve();
    
    return 0;
}

void solve() {
    cin >> N;
    for (int i = 0; i < (int)N; ++i) {
        char digit;
        cin >> digit;
        A[i] = (lli)(digit - '0');
    }

    for (int i = (int)N - 1; i >= 0; --i)
        d0[i] = d0[i + 1] + (A[i] == 0LL ? 1LL : 0LL);
    for (int i = (int)N - 1; i >= 0; --i)
        d20[i] = d20[i + 1] + (A[i] == 2LL ? d0[i + 1] : 0LL);
    for (int i = (int)N - 1; i >= 0; --i)
        d020[i] = d020[i + 1] + (A[i] == 0LL ? d20[i + 1] : 0LL);
    for (int i = (int)N - 1; i >= 0; --i)
        d4020[i] = d4020[i + 1] + (A[i] == 4LL ? d020[i + 1] : 0LL);
    
    cout << d4020[0] << '\n';
    return;
}
