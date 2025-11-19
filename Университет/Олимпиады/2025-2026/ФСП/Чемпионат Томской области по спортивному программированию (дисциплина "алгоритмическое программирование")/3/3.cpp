// author:		Danila "akshin_" Axyonov
// password:	28092025

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long int lli;

#define pb(_elem)				push_back(_elem)
#define mp(_first, _second)		make_pair(_first, _second)

void solve();
lli _abs(lli num);

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	solve();

	return 0;
}

void solve() {
	lli n;
	cin >> n;
	vector<lli> a(n);
	for (lli& ai : a)
		cin >> ai;
	sort(a.begin(), a.end());

	lli S = 0LL;
	for (int i = 0; i < (int)n; i += 2)
		S += _abs(a[i] - a[i + 1]);

	cout << (n >> 1) << '\n'
		 << S << '\n';
	return;
}

lli _abs(lli num) {
	return (num >= 0LL ? num : -num);
}

