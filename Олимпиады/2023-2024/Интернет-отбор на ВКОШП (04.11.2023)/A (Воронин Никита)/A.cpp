#include <iostream>
#define ll long long
using namespace std;

ll n, m, k, ans;

int main() {
	cin >> n >> m >> k;
	if (k - n % k != k)
		n += k - n % k;
	if (k - m % k != k)
		m += k - m % k;
	ans = (n / k) * (m / k);
	cout << ans << endl;
	return 0;
}

