// author: Danila "akshin_" Aksionov

#include <iostream>
#include <cmath>
using namespace std;
typedef long long int lli;

#define plli                pair<lli, lli>
#define mp(_first, _second) make_pair(_first, _second)
#define pb(_elem)           push_back(_elem)

const lli N = 6LL;

lli A[N];
lli x;

void solve();
lli get_n_factorial(lli);
lli _pow(lli, lli);

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    solve();
    
    return 0;
}

void solve() {
    for (lli i = 0LL; i < N; ++i)
        A[i] = get_n_factorial(i);
    
    cin >> x;
    for (int i = 0; i < (int)N; ++i)
        for (int j = i; j < (int)N; ++j)
            if (A[i] + A[j] == x) {
                cout << "YES\n";
                return;
            }

    cout << "NO\n";
    return;
}

lli get_n_factorial(lli m) {
    lli ans = 1LL;
    for (lli k = 2LL; k <= m; ++k)
        ans *= _pow(k, k);
    return ans;
}

lli _pow(lli base, lli pointer) {
    if (pointer == 0LL)
        return 1LL;
    if (pointer % 2LL == 0LL) {
        lli tmp = _pow(base, pointer / 2LL);
        return tmp * tmp;
    }
    return base * _pow(base, pointer - 1LL);
}
