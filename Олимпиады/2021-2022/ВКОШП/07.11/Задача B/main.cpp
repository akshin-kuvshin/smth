#include <iostream>
using namespace std;

// Variables
long long a,
		  b,
		  answer;

// Functions
void input();
void solution();
void output();
long long get_scans_amount(long long, long long);

int main() {
	input();
	solution();
	output();
	
	return 0;
}

void input() {
	cin >> a >> b;
	return;
}

void solution() {
	answer = get_scans_amount(a, b);
	return;
}

void output() {
	cout << answer << '\n';
	return;
}

long long get_scans_amount(long long x, long long y) {
	if (x > y)
		return get_scans_amount(y, x);
	if (x == 0)
		return 0;
	
	return (y / x + get_scans_amount(y % x, x) );
}
