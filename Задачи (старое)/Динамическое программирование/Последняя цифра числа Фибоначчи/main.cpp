#include <iostream>
using namespace std;

// Constants
const int N_max = 1e3;

// Variables
int N,
	cache[N_max + 5] = {1, 1};

// Functions
int fib_last_digit(int num) {
	if (cache[num]) return cache[num];
	return cache[num] = (fib_last_digit(num - 1) % 10 + fib_last_digit(num - 2) % 10) % 10;
}

int main() {
	cin >> N;
	cout << fib_last_digit(N) << '\n';

	return 0;
}

