#include <iostream>
using namespace std;

// Constants
const int N_max = 1e3;

// Variables
int N;
long long cache[N_max + 5] = {1, 1};

// Functions
long long sequence(int num) {
	if (cache[num]) return cache[num];
	if (num % 2 == 0) return cache[num] = sequence(num / 2) + 1;
	return cache[num] = sequence(num - 1) + sequence( (num - 1) / 2 + 1);
}

int main() {
	cin >> N;
	cout << sequence(N) << '\n';
	
	return 0;
}
