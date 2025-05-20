// author: Danila "akshin_" Axyonov

#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;
using lli = long long int;

void solve();

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	lli Q;
	cin >> Q;
	while (Q--)
		solve();
	
	return 0;
}

void solve() {
	string S;
	cin >> S;
	unordered_map<char, lli> m;
	for (char c : S)
		++m[c];
	lli ans = -1LL;
	for (auto [_, cnt] : m)
		if (cnt > 1LL)
			ans = 1LL;
	if (ans == -1LL)
		ans = (lli)S.size();
	cout << ans << '\n';
	return;
}
