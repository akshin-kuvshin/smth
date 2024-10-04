// author: Danila "akshin_" Axyonov

#include <iostream>
#include <vector>
using namespace std;
typedef long long int lli;

lli bs(vector<lli>&, lli);
bool f(vector<lli>, lli, lli);

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	lli N;
	cin >> N;
	
	vector<lli> A(N);
	for (lli &elem : A)
		cin >> elem;
	
	lli ans = bs(A, N);
	cout << ans << '\n';
		
	return 0;
}

lli bs(vector<lli> &A, lli N) {
	lli l = 0LL,
		r = (lli)1e18 + 1LL;
	while (l + 1LL < r) {
		lli mid = (l + r) >> 1;
		if (f(A, N, mid))
			r = mid;
		else
			l = mid;
	}
	return r;
}


bool f(vector<lli> A, lli N, lli x) {
	for (int i = 0; i + 1 < (int)N; ++i) {
		if (A[i] >= x)
			return false;
		A[i + 1] = max(A[i + 1] - A[i], 0LL);
	}
	if (A.back() < x)
		return true;
	return false;
}
