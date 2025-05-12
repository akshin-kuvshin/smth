// author: Danila "akshin_" Axyonov

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
using lli = long long int;

#define plli                pair<lli, lli>
#define mp(_first, _second) make_pair(_first, _second)
#define pb(_elem)           push_back(_elem)

const lli N_MAX = (lli)7e6 + 5LL;
vector<lli> primes;

void solve();

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    vector<bool> is_prime(N_MAX);
    fill(is_prime.begin(), is_prime.end(), true);
    for (lli i = 2LL; i * i <= N_MAX; ++i) {
        if (not is_prime[i])
            continue;
        for (lli j = i * i; j <= N_MAX; j += i)
            is_prime[j] = false;
    }
    for (lli i = 2LL; i <= N_MAX; ++i)
        if (is_prime[i])
            primes.pb(i);
    
    lli Q;
    cin >> Q;
    while (Q--)
        solve();
    
    return 0;
}

void solve() {
    lli n;
    cin >> n;
    vector<lli> a(n);
    lli a_sum = 0LL;
    for (lli& ai : a) {
        cin >> ai;
        a_sum += ai;
    }
    sort(a.begin(), a.end());

    lli p_sum = 0LL;
    for (int i = 0; i < (int)n; ++i)
        p_sum += primes[i];
    
    lli k = 0LL;
    while (a_sum < p_sum) {
        a_sum -= a[k];
        p_sum -= primes[(int)n - 1 - (int)k];
        ++k;
    }
    cout << k << '\n';

    return;
}
