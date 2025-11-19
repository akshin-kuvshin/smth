// author:		Danila "akshin_" Axyonov
// password:	28092025

#include <iostream>
using namespace std;
typedef long long int lli;

#define pb(_elem)				push_back(_elem)
#define mp(_first, _second)		make_pair(_first, _second)

void solve();

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	solve();

	return 0;
}

void solve() {
	lli n;
	cin >> n;

	lli d = 2LL;
	while (d * d <= n) {
		while (n % d == 0LL) {
			n /= d;
			cout << d << ' ';
		}
		++d;
	}
	if (n > 1LL)
		cout << n << ' ';
	cout << '\n';

	return;
}

