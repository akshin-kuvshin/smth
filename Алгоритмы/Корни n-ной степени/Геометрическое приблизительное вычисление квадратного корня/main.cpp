#include <iostream>
using namespace std;

// Variables
int number;
double answer;

// Functions
void input();
void solution();
void output();
double _sqrt(int);

int main() {
	input();
	solution();
	output();
	
	return 0;
}

void input() {
	cin >> number;
}

void solution() {
	if (number == 0)
		return;
	answer = _sqrt(number);
}

void output() {
	cout << answer << '\n';
}

double _sqrt(int num) {
	double a = 1,
		   b = num;
	
	for (int i = 0; i < 100; i++) {
		a = (a + b) / 2;
		b = num / a;
	}
	
	return a;
}
