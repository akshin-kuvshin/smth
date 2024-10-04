#include <iostream>
using namespace std;

// Variables
int x,
	y,
	z,
	a,
	b,
	c;

// Functions
void input();
void solution();
void output();

int gcd_R(int n, int k) {
	return (n && k) ? gcd_R(k, n % k) : (n | k);
}

int main() {
	input();
	solution();
	output();
	return 0;
}

void input() {
	cin >> x >> y >> z;
//	return;
}

void solution() {
	a = gcd_R(x, z);
	b = x / a;
	c = y / b;
	
//	return;
}

void output() {
	cout << a << ' ' << b << ' ' << c << '\n';
//	return;
}
