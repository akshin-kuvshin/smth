// author: Danila "akshin_" Aksionov

#include <iostream>
#include <algorithm> // for std::fill
using namespace std;
typedef long long int lli;

#define plli                pair<lli, lli>
#define mp(_first, _second) make_pair(_first, _second)
#define pb(_elem)           push_back(_elem)

#define NON_DEF             -1LL

const lli MAX_SIZE = 45LL + 5LL;

lli n;
lli cache[MAX_SIZE];

void solve();
lli fib(lli);

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    fill(cache, cache + MAX_SIZE, NON_DEF);
    cache[0] = 0LL;
    cache[1] = 1LL;
    solve();
    
    return 0;
}

void solve() {
    cin >> n;
    cout << fib(n) << '\n';
    return;
}

lli fib(lli ind) {
    return ((cache[ind] != NON_DEF) ? cache[ind] : (cache[ind] = fib(ind - 1LL) + fib(ind - 2LL)));
}
