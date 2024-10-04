// author: Danila "akshin_" Aksionov

#include <iostream>
#include <algorithm>
using namespace std;
typedef long long int lli;

#define plli                pair<lli, lli>
#define mp(_first, _second) make_pair(_first, _second)
#define pb(_elem)           push_back(_elem)

const lli N = (lli)16e6 + 1LL;
bool prime[N];

lli K;
lli cur,
	cur_ind;

void solve();
void fill_primes();

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    solve();
    
    return 0;
}

void solve() {
	fill_primes();
	
	cin >> K;
	for (lli i = 0LL; i < N and cur_ind < K; ++i)
		if (prime[i]) {
			cur = i;
			++cur_ind;
		}
	
	cout << cur << '\n';
    return;
}

void fill_primes() {
	fill(prime + 1LL, prime + N, true);
	
	prime[0] = prime[1] = false;
	for (lli i = 2LL; i < N; ++i) {
		if (!prime[i])
			continue;
		for (lli j = i * i; j < N; j += i)
			prime[j] = false;
	}
	
	return;
}
