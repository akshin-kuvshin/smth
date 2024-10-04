// author: Danila "akshin_" Axyonov

#include <iostream>
using namespace std;
typedef long long int lli;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	lli a,
		b,
		c,
		d;
	cin >> a >> b >> c >> d;
	
	lli cnt = 0LL;
	while (5LL * a + 4LL * b + 3LL * c + 2LL * d < 4LL * (a + b + c + d)) {
		++a;
		++cnt;
	}
	
	cout << cnt << '\n';	
	return 0;
}
