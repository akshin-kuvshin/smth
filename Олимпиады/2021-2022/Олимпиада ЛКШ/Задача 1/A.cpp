#include <iostream>
using namespace std;

// Variables
long long a,
		  b;

// Functions
void input();
void solution();
long long gcd(long long, long long);

int main() {
	input();
	solution();
	return 0;
}

void input() {
	cin >> a >> b;
	return;
}

void solution() {
	if (b % a) {
		cout << 0 << '\n';
		return;
	} if (gcd(a, b / a) == 1)
		cout << 2;
	else
		cout << 1;
	cout << '\n';
	
	return;
}

long long gcd(long long x, long long y) {
	return ( (x && y) ? gcd(y, x % y) : (x | y) );
}
