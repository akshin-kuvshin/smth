// author: Danila "akshin_" Axyonov

#include <iostream>
using namespace std;
typedef long long int lli;

const lli MAX_SIZE = (lli)1e6 + 5LL;

lli K,
	P;
lli dp[MAX_SIZE];

void solve();

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	solve();
	
	return 0;
}

void solve() {
	cin >> K >> P;
	
	dp[2] = 1LL;
	for (int i = 3; i <= (int)K; ++i) {
		dp[i] += dp[i - 1];
		if (i % 2 == 0)
			dp[i] += dp[i / 2];
		dp[i] %= P;
	}
	
	cout << dp[K] << '\n';
	return;
}
