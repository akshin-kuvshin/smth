// FINAL (100/100)

#include <iostream>
using namespace std;

typedef long long int lli;

lli N,
	M,
	A,
	B;
lli timer,
	dt1,
	dt2;

// lli gcd_R(lli, lli);
lli _abs(lli);

int main() {
	cin >> N >> M >> A >> B;
	
	while (N || M) {
		if (_abs(N - M) > 1LL)
			++timer;
		else {
			dt1 = A - timer % A;
			dt2 = B - timer % B;
			timer += min(dt1, dt2);
		}
		
		if (N && (timer % A == 0LL))
			--N;
		if (M && (timer % B == 0LL))
			--M;
		if (N && (N > M + 1LL)) {
			--N;
			++M;
		}
		if (M && (M > N + 1LL)) {
			--M;
			++N;
		}
	}
	
	cout << timer << '\n';
	return 0;
}

/* lli gcd_R(lli x, lli y) {
	return ((x && y) ? gcd_R(y, x % y) : (x | y));
} */

lli _abs(lli num) {
	if (num < 0LL) return -num;
	return num;
}
