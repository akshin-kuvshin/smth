#include <iostream>
using namespace std;

// Variables
int n,
	answer;

// Functions
int fib(int, int, int);

int main() {
	// Input
	cin >> n;
	
	// Solution
	if (n == 0)
		answer = 0;
	else
		answer = fib(0, 1, 1);
	
	// Output
	cout << answer << '\n';
	
	return 0;
}

int fib(int a, int b, int index) {
	if (index == n)
		return b;
	return fib(b, a + b, index + 1);
}
