// author: Danila "akshin_" Axyonov

#include <iostream>
using namespace std;
typedef long long int lli;
typedef unsigned long long int ulli;

#define plli                pair<lli, lli>
#define mp(_first, _second) make_pair(_first, _second)
#define pb(_elem)           push_back(_elem)

void solve();
int len2(ulli);

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    solve();
    
    return 0;
}

void solve() {
    ulli N;
    cin >> N;
    
    if (((N + 1ULL) & N) == 0ULL) {
        cout << "0 " << N << '\n';
        return;
    }

    int len = len2(N);
    lli b = (1ULL << (len - 1)) - 1ULL;
    lli a = N - b;
    cout << a << ' ' << b << '\n';    
    return;
}

int len2(ulli N) {
    int res = 0;
    while (N) {
        N >>= 1;
        ++res;
    }
    return res;
}
