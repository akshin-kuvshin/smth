// author:		Danila "akshin_" Axyonov
// password:	28092025

#include <iostream>
#include <string>
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
		k;
	cin >> n >> k;

	string S;
	cin >> S;
	unordered_map<char, lli> m;
	for (char c : S)
		++m[c];
	
	bool answer = (m['S'] - 3LL * (k - 1LL) > 0LL) and
				  (m['M'] - 3LL * (k - 1LL) > 0LL) and
				  (m['L'] - 3LL * (k - 1LL) > 0LL);
	cout << (answer ? "YES" : "NO") << '\n';
	return;
}

