#include <iostream>
using namespace std;
typedef long long int lli;

lli A,
	B,
	C,
	D,
	E,
	F;
lli _sum,
	_sum1,
	_sum2;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	cin >> A >> B >> C >> D >> E >> F;
	
	_sum1 = A + B + C;
	_sum2 = D + E + F;
	_sum = _sum1 + _sum2;
	
	cout << _sum << ' ' << ((A > D) ? 1 : 2) << '\n';
	
	return 0;
}
