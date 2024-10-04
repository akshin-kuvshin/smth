// author: Danila "akshin_" Axyonov

#include <iostream>
#include <cmath> // for std::abs
using namespace std;
typedef long long int lli;

const lli MAX_SIZE = (lli)3e4 + 5LL;

lli N,
	A[MAX_SIZE];
lli dp[MAX_SIZE];

void solve();

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	solve();
	
	return 0;
}

void solve() {
	cin >> N;
	for (int i = 1; i <= (int)N; ++i)
		cin >> A[i];
	
	dp[1] = 0LL;
	dp[2] = abs(A[1] - A[2]);
	for (int i = 3; i <= (int)N; ++i)
		dp[i] = min(dp[i - 1] + abs(A[i - 1] - A[i]), dp[i - 2] + 3LL * abs(A[i - 2] - A[i]));
	
	cout << dp[N] << '\n';
	return;
}
