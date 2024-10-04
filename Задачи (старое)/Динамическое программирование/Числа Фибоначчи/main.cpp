#include <iostream>
using namespace std;

// Constants
const int N_max = 46;

// Variables
int N;
long long cache[N_max + 5] = {0, 1, 1};

// Functions
long long fib(int N) {
	if (cache[N]) return cache[N];
	return cache[N] = fib(N - 1) + fib(N - 2);
}

int main() {
	cin >> N;
	cout << fib(N) << '\n';

	return 0;
}

