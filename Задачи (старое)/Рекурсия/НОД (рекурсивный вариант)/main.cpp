#include <iostream>
using namespace std;

// Variables
int a,
	b,
	_gcd;

// Functions
int find_gcd(int, int);

int main() {
	// Input
	cin >> a >> b;
	
	// Solution
	_gcd = find_gcd(a, b);
	
	// Output
	cout << _gcd << '\n';
	
	return 0;
}

int find_gcd(int x, int y) {
	return (y ? find_gcd(y, x % y) : x);
}
