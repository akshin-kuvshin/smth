#include <iostream>
using namespace std;

int num1,
	num2;

int _gcd(int, int);

int main() {
	cin >> num1 >> num2;
	cout << _gcd(num1, num2) << '\n';

	return 0;
}

int _gcd(int a, int b) {
	return (a && b) ? _gcd(b, a % b) : (a | b);
}
