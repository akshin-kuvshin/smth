// author: Danila "akshin_" Axyonov

#include <iostream>
using namespace std;
typedef long long int lli;

lli A,
	B;
lli ans;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	cin >> A >> B;
	ans = A + 2LL * B;
	cout << ans << '\n';
	
	return 0;
}
