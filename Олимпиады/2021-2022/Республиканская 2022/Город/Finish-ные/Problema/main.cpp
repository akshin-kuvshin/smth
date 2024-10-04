#include <iostream>
using namespace std;

// Variables
int a,
	b,
	c,
	d,
	x,
	y,
	_ans;

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
	cin >> a >> b >> c >> d;
//	return;
}

void solution() {
	x = min(a, c);
	y = min(b, d);
	
	_ans = x * y;
	
//	return;
}

void output() {
	cout << _ans << '\n';
//	return;
}
