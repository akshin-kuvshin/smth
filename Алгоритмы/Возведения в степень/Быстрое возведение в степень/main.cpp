#include <iostream>
using namespace std;

// Variables
int a, // основание
	n, // показатель
	answer; // ответ

// Functions
void input();
void solution();
void output();
int _pow(int, int);

int main() {
	input();
	solution();
	output();

	return 0;
}

void input() {
	cin >> a >> n;
}

void solution() {
	answer = _pow(a, n);
}

void output() {
	cout << answer << '\n';
}

int _pow(int base, int pointer) {
	int k = 1; // возвращаемое значение

	while (pointer != 0) {
		if (pointer % 2 == 0) {
			base *= base;
			pointer /= 2;
		} else {
			k *= base;
			pointer--;
		}
	}

	return k;
}
