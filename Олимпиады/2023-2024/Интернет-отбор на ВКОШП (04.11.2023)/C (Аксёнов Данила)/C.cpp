#include <iostream>
using namespace std;
typedef long long int lli;

const lli MAX_SIZE = (lli)1e6;
lli dp[MAX_SIZE + 5LL];

lli h,
	w;

void count_dp();
void solve();
lli f(lli, lli);

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	count_dp();
	solve();
	
	return 0;
}

void count_dp() {
	dp[1] = 1;
	for (int i = 2; i <= (int)MAX_SIZE; ++i)
		dp[i] = (lli)i + dp[i - 1] + dp[1];
	return;
}

void solve() {
	cin >> h >> w;
	cout << f(h, w) << '\n';
	return;
}

lli f(lli x, lli y) {
	if (x > y)
		return f(y, x);
	if (x == 1LL)
		return dp[y];
	return x * y + f(x, y - 1LL) + f(x, 1LL);
}
