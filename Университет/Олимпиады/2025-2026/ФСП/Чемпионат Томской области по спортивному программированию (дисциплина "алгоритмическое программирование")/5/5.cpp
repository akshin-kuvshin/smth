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
	lli n,
		a,
		b;
	cin >> n >> a >> b;

	lli S = 0LL;
	if (a * 3LL < (b << 1)) {
		if (n & 1LL) {
			S += b;
			n -= 3LL;
		}
		S += a * (n >> 1);
	} else { // a / 2. > b / 3.
		if (n % 3LL == 1LL) {
			S += a << 1;
			n -= 4LL;
		} else if (n % 3LL == 2LL) {
			S += a;
			n -= 2LL;
		}
		S += b * (n / 3LL);
	}

	cout << S << '\n';
	return;
}

