// author:		Danila "akshin_" Axyonov
// password:	28092025

#include <iostream>
#include <string>
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

	string password;
	char c;
	while (n--) {
		cin >> c;
		if (c == '<') {
			if (not password.empty())
				password.pop_back();
		} else
			password.pb(c);
	}

	cout << password << '\n';
	return;
}

