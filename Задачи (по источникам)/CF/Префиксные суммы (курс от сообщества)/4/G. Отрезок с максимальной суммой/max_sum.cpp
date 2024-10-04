#include <iostream>
#define _sum first
#define index second
using namespace std;

typedef long long int lli;

const lli N_max = 100000LL,
		  VERY_LITTLE_NUMBER = -2000000000LL;

lli N,
	A[N_max + 5LL],
	B[N_max + 5LL];
pair<lli, lli> prefix_min[N_max + 5LL];
lli l,
	r,
	max_sum = VERY_LITTLE_NUMBER;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> N;
	for (int i = 0; i < (int)N; ++i) {
		cin >> A[i];
		B[i + 1] = B[i] + A[i];
		prefix_min[i + 1] = min(prefix_min[i], make_pair(B[i + 1], (lli)i + 1LL));
	}

	for (int i = 1; i <= (int)N; ++i)
		if (max_sum < B[i] - prefix_min[i - 1]._sum) {
			l = prefix_min[i - 1].index + 1LL;
			r = i;
			max_sum = B[i] - prefix_min[i - 1]._sum;
		}

	cout << l << ' ' << r << ' ' << max_sum << '\n';
	return 0;
}
