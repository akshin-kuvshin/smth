// author: Danila "akshin_" Aksionov

#include <iostream>
#include <map>
using namespace std;
typedef long long int lli;

#define plli                pair<lli, lli>
#define mp(_first, _second) make_pair(_first, _second)
#define pb(_elem)           push_back(_elem)

lli A,
    _A;
map<lli, lli> m;
lli N,
    N0;

void solve();
void factorize();
lli _pow(lli, lli);

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    solve();
    
    return 0;
}

void solve() {
    cin >> A;
    _A = A;
    
    factorize();
    N = 1LL;
    for (plli p : m)
        N *= p.first;
    
    N0 = N;
    while (_pow(N, N) % A != 0LL)
        N += N0;

    cout << N << '\n';
    return;
}

void factorize() {
    for (lli d = 2LL; d * d <= _A; ++d)
        while (_A % d == 0LL) {
            ++m[d];
            _A /= d;
        }
    if (_A > 1LL)
        ++m[_A];
    return;
}

lli _pow(lli base, lli ptr) {
    if (ptr == 0LL)
        return 1LL;
    if (ptr % 2LL == 0LL) {
        lli half = _pow(base, ptr / 2LL);
        return half * half;
    }
    return base * _pow(base, ptr - 1LL);
}
