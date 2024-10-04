#include <iostream>
#include <cmath>
using namespace std;

// Variables
long long s,
		  a,
		  b,
		  prod;
bool flag;

// Functions
void input();
void solution();
void output();
void find_higher();
void find_lower();
int get_answer();

int main() {
	input();
	solution();
	output();		
	
	return 0;
}

void input() {
	cin >> s;
}

void solution() {
	a = b = round(sqrt(s));
	prod = a * b;
	
	if (prod > s)
		find_higher();
	else if (prod < s)
		find_lower();
}

void output() {
	cout << get_answer() << '\n';
}

void find_higher() {
	while (prod >= s) {
		if (flag) {
			a--;
			prod -= b;
		} else {
			b--;
			prod -= a;
		}
		
		flag = !flag;
	}
	
	if (flag)
		b++;
	else
		a++;
}

void find_lower() {
	while (prod < s) {
		if (flag) {
			a++;
			prod += b;
		} else {
			b++;
			prod += a;
		}
		
		flag = !flag;
	}
}

int get_answer() {
	return a + b;
}
