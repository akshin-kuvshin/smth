// author: Danila "akshin_" Axyonov

#include <iostream>
using namespace std;
typedef long long int lli;

lli bs(lli);
bool f(lli, lli);

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	lli N;
	cin >> N;
	N *= 4LL;
	
	lli ans = bs(N);
	cout << ans << '\n';
	
	return 0;
}

lli bs(lli N) {
	lli l = 0LL,
		r = (lli)1e18 + 1LL;
	while (l + 1LL < r) {
		lli mid = (l + r) >> 1;
		if (f(N, mid))
			l = mid;
		else
			r = mid;
	}
	return l;
}

bool f(lli N, lli x) {
	N -= 3LL * x;
	
	if (N % 2LL == 0LL)
		N *= 2LL;
	else // N % 2LL == 1LL
		N = (N - 1LL) * 2LL;
	
	return (N >= 2LL * x);
}
