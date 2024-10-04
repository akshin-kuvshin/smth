// author: Danila "akshin_" Axyonov

#include <iostream>
#include <cmath>
using namespace std;
typedef long long int lli;

const double eps = 1e-6;

lli N,
	cur,
	sum,
	cnt;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	cin >> N;
	for (lli _ = 0LL; _ < N; ++_) {
		cin >> cur;
		if (_ == 0LL)
			cout << "0\n";
		else if (abs((double)cur - (double)sum / (double)cnt) < eps)
			cout << "0\n";
		else if ((double)cur < (double)sum / (double)cnt)
			cout << "<\n";
		else // (double)cur > (double)sum / (double)cnt
			cout << ">\n";
		sum += cur;
		++cnt;
	}
	
	return 0;
}
