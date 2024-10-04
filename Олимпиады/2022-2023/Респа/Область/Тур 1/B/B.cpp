// FINAL (44/100)

#include <iostream>
using namespace std;

typedef long long int lli;

const lli MAX_SIZE = 200000LL;

lli N,
	K,
	S[MAX_SIZE + 5LL];
lli max_elem,
	sum,
	max_sum;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	cin >> N >> K;
	for (int i = 0; i < (lli)N; ++i) {
		cin >> S[i];
		max_elem = max(max_elem, S[i]);
	}
	
	if (max_elem < K) {
		cout << "0\n";
		return 0;
	}
	
	if (K == 0LL) {
		for (int i = 0; i < (int)N; ++i)
			sum += S[i];
		cout << sum << '\n';
		return 0;
	}
	
	for (lli x = max_elem; x >= K; --x) {
		sum = 0LL;
		for (int i = 0; i < (int)N; ++i)
			sum += S[i] / x;
		sum *= (x - K);
		max_sum = max(max_sum, sum);
	}
	
	cout << max_sum << '\n';
	return 0;
}
