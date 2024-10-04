#include <iostream>
using namespace std;

// Variables
int a,
	b,
	gcd;

// Functions
void input();
void solution();
void output();
int binaryGCD(int, int);
int _abs(int);

int main() {
	input();
	solution();
	output();
	
	return 0;
}

void input() {
	cin >> a >> b;
}

void solution() {
	a = _abs(a);
	b = _abs(b);
	
	gcd = binaryGCD(a, b);
}

void output() {
	cout << gcd << '\n';
}

int binaryGCD(int num1, int num2) {
	if ( (num1 == 0) or (num2 == 0) )
		return num1 + num2;
	if (num1 == num2)
		return num1;
	if ( (num1 % 2 == 0) and (num2 % 2 == 0) )
		return 2 * binaryGCD(num1 / 2, num2 / 2);
	if ( (num1 % 2 == 0) and (num2 % 2 != 0) )
		return binaryGCD(num1 / 2, num2);
	if ( (num1 % 2 != 0) and (num2 % 2 == 0) )
		return binaryGCD(num1, num2 / 2);
	if ( (num1 % 2 != 0) and (num2 % 2 != 0) and (num1 < num2) )
		return binaryGCD((num2 - num1) / 2, num1);
	if ( (num1 % 2 != 0) and (num2 % 2 != 0) and (num1 > num2) )
		return binaryGCD((num1 - num2) / 2, num2);
}

int _abs(int number) {
	if (number >= 0)
		return number;
	return -number;
}
