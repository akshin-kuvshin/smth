// author: Danila "akshin_" Axyonov

#include <iostream>
using namespace std;
typedef long long int lli;

const lli MAX_SIZE = (lli)5e3 + 5LL,
		  INF = (lli)1e18 + 1LL;

class Buyer {
public:
	lli A;
	lli B;
	lli C;
};

lli N;
Buyer q[MAX_SIZE];
lli dp[MAX_SIZE][4]; // dp[i][0] - не используется
					 // dp[i][1] - минимальное время, за которое будет обслужен i-тый покупатель, если он будет покупать свой билет сам.
					 // dp[i][2] - минимальное время, за которое будет обслужен i-тый покупатель, если он отдаст свой билет впереди стоящему покупателю.
					 // dp[i][3] - минимальное время, за которое будет обслужен i-тый покупатель, если он отдаст свой билет человеку спереди через одного.
lli ans;

void solve();
lli min(lli, lli, lli);

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	solve();
	
	return 0;
}

void solve() {
	cin >> N;
	for (int i = 0; i < (int)N; ++i)
		cin >> q[i].A >> q[i].B >> q[i].C;
	
	if (N < 4LL) {
		if (N == 1LL)
			cout << q[0].A;
		else if (N == 2LL)
			cout << min(q[0].A + q[1].A, q[0].B);
		else // if (N == 3LL)
			cout << min(
				min(q[0].A + q[1].A, q[0].B) + q[2].A,
				q[0].A + q[1].B,
				q[0].C
			);
		cout << '\n';
		return;
	}
	
	dp[0][1] = q[0].A;
	dp[0][2] = INF;
	dp[0][3] = INF;
	dp[1][1] = dp[0][1] + q[1].A;
	dp[1][2] = q[0].B;
	dp[1][3] = INF;
	dp[2][1] = min(dp[1][1], dp[1][2]) + q[2].A;
	dp[2][2] = dp[0][1] + q[1].B;
	dp[2][3] = q[0].C;
	for (int i = 3; i < (int)N; ++i) {
		dp[i][1] = min(dp[i - 1][1], dp[i - 1][2], dp[i - 1][3]) + q[i].A;
		dp[i][2] = min(dp[i - 2][1], dp[i - 2][2], dp[i - 2][3]) + q[i - 1].B;
		dp[i][3] = min(dp[i - 3][1], dp[i - 3][2], dp[i - 3][3]) + q[i - 2].C;
	}
	
	ans = min(dp[N - 1LL][1], dp[N - 1LL][2], dp[N - 1LL][3]);
	cout << ans << '\n';
	return;
}

lli min(lli num1, lli num2, lli num3) {
	return min(num1, min(num2, num3));
}
