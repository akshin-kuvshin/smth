#include <iostream>
#define dot pair<int, int>
#define x first
#define y second
using namespace std;

// Variables
dot A,
	B;

// Functions
int gcd_R(int num1, int num2) {
	return (num1 && num2) ? gcd_R(num2, num1 % num2) : (num1 | num2);
}

int main() {
	cin >> A.x >> A.y >> B.x >> B.y;
	cout << gcd_R(abs(B.x - A.x), abs(B.y - A.y)) - 1 << '\n';	
	return 0;
}
