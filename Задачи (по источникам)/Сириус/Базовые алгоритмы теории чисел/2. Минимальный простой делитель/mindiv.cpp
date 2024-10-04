// author: Danila "akshin_" Aksionov

#include <iostream>
using namespace std;
typedef long long int lli;

#define plli                pair<lli, lli>
#define mp(_first, _second) make_pair(_first, _second)
#define pb(_elem)           push_back(_elem)

lli N;

void solve();
lli min_prime_div(lli);

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    solve();
    
    return 0;
}

void solve() {
	cin >> N;
	cout << min_prime_div(N) << '\n';	
    return;
}

lli min_prime_div(lli num) {
	for (lli d = 2LL; d * d <= num; ++d)
		if (num % d == 0LL)
			return d;
	return num;
}

