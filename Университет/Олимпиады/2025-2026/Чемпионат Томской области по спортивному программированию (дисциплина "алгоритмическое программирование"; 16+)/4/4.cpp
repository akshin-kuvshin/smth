// author:		Danila "akshin_" Axyonov
// password:	28092025

#include <iostream>
#include <vector>
#include <unordered_map>
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
		t;
	cin >> n >> t;
	vector<lli> a(n);
	for (lli& ai : a)
		cin >> ai;

	unordered_map<lli, lli> m;
	for (lli ai : a)
		++m[ai];

	lli p = -1LL,
		q = -1LL;
	for (lli ai : a)
		if (m[t - ai] > 0LL) {
			p = ai;
			q = t - ai;
			break;
		}

	if (p == -1LL or q == -1LL)
		cout << "WATAFAK";
	else // p != -1LL and q != -1LL
		cout << p << ' ' << q;
	cout << '\n';
	return;
}

