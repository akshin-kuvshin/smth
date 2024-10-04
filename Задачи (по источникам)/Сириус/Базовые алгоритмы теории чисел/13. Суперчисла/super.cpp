// author: Danila "akshin_" Aksionov

#include <iostream>
#include <algorithm>
#include <set>
using namespace std;
typedef long long int lli;

#define plli                pair<lli, lli>
#define mp(_first, _second) make_pair(_first, _second)
#define pb(_elem)           push_back(_elem)

const lli N_MAX = (lli)4e4 + 5LL,
          MAX_SIZE = (lli)2e7;

lli A,
    B;

bool prime[N_MAX];
lli primes[N_MAX],
    primes_top;
lli super[MAX_SIZE],
    super_top;

void solve();
void fill_prime();
void fill_primes();
void make_super();
lli bs();

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    solve();
    
    return 0;
}

void solve() {
    fill_prime();
    fill_primes();
    make_super();

    cin >> A >> B;

    lli start = bs();
    for (int i = (int)start; i < (int)super_top and super[i] <= B; ++i)
        cout << super[i] << '\n';

    return;
}

// Erathosphene's sieve
void fill_prime() {
    fill(prime, prime + N_MAX, true);

    prime[0] = prime[1] = false;
    // Выгоднее в условии цикла написать i * i <= (int)N_MAX
    for (int i = 2; i < (int)N_MAX; ++i) {
        if (!prime[i])
            continue;
        for (int j = i * i; j < (int)N_MAX; j += i)
            prime[j] = false;
    }

    return;
}

void fill_primes() {
    for (int i = 0; i < (int)N_MAX; ++i)
        if (prime[i])
            primes[primes_top++] = (lli)i;
    return;
}

void make_super() {
    set<lli> S;
    for (int i = 0; i < (int)primes_top; ++i)
	for (int j = i; j < (int)primes_top and primes[i] + primes[j] < N_MAX; ++j)
            S.insert(primes[i] + primes[j]);
    
    for (lli elem : S)
        super[super_top++] = elem;
    
    return;
}

lli bs() {
    lli l = -1LL,
        r = super_top - 1LL;
    while (l + 1LL < r) {
        lli mid = (l + r) >> 1;
        if (super[mid] < A)
            l = mid;
        else
            r = mid;
    }
    return r;
}
