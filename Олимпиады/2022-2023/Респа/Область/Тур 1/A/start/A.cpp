// FINAL (70/100)

#include <iostream>
#include <string>
using namespace std;

typedef long long int lli;

const lli MAX_SIZE = 100000LL;

lli N,
	Q,
	A[MAX_SIZE + 5LL],
	x;
bool answer,
	 flag;
string ans[] = {"NO\n", "YES\n"};

lli gcd_R(lli, lli);

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	cin >> N >> Q;
	for (int i = 0; i < (int)N; ++i)
		cin >> A[i];
	
	while (Q--) {
		cin >> x;
		
		answer = flag = true;
		for (int i = 0; i < (int)N and flag; ++i)
			for (int j = i + 1; j < (int)N and flag; ++j)
				if (gcd_R(A[i] + x, A[j] + x) != 1LL) {
					answer = false;
					flag = false;
				}
		
		cout << ans[answer];
	}
}

lli gcd_R(lli num1, lli num2) {
	return ((num1 && num2) ? gcd_R(num2, num1 % num2) : (num1 | num2));
}
