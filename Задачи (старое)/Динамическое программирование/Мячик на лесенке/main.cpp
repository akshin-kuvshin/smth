#include <iostream>
using namespace std;

// Constants
const int N_max = 31;

// Variables
int N;
long long cache[N_max + 5] = {1, 1, 2};

// Functions
long long get_ways_amount(int num) {
	if (cache[num]) return cache[num];
	return cache[num] = get_ways_amount(num - 1) + get_ways_amount(num - 2) + get_ways_amount(num - 3);
}

int main() {
	cin >> N;
	cout << get_ways_amount(N) << '\n';
	
	return 0;
}
