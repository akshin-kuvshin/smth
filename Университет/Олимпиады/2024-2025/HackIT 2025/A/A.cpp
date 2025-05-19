// author: Danila "akshin_" Axyonov

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
using lli = long long int;

void solve();

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	solve();
	
	return 0;
}

void solve() {
	lli n,
		m,
		d;
	cin >> n >> m >> d;
	vector<lli> l(m);
	for (lli& li : l)
		cin >> li;
	sort(l.begin(), l.end());
	
	lli b = 0LL,
		e = m - 1LL,
		cnt = 0LL;
	while (e >= 0LL and d <= l[e]) {
		--e;
		++cnt;
	}
	while (b < e) {
		while (b < e and d > l[b] + l[e] - 1LL)
			++b;
		if (b < e) {
			++b;
			--e;
			++cnt;
		}
	}
	cout << (cnt >= n ? "YES\n" : "NO\n");
	return;
}
