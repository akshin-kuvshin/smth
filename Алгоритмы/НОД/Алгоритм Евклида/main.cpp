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
int _abs(int);
void swap_int(int&, int&);

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
	
	if (a < b)
		swap_int(a, b);
	
	while (b != 0) {
		a %= b;
		swap_int(a, b);
	}
	gcd = a;
}

void output() {
	cout << gcd << '\n';
}

int _abs(int num) {
	if (num >= 0)
		return num;
	return -num;
}

void swap_int(int &num1, int &num2) {
	num1 = num1 ^ num2;
	num2 = num1 ^ num2;
	num1 = num1 ^ num2;
}
