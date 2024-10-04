#include <iostream>
using namespace std;

// Variables
int h,
	a,
	b,
	days;

// Functions
void input();
void solution();
void output();

int main() {
	input();
	solution();
	output();
	
	return 0;
}

void input() {
	cin >> h >> a >> b;
}

void solution() {
	h -= a;
	days = 1;
	
	days += (h / (a - b) + 1 % (h % (a - b) + 1) ) * (h > 0);	
}

void output() {
	cout << days << '\n';
}
