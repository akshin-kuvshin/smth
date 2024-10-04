#include <iostream>
#include <string>
using namespace std;

// Variables
int size, maxDigit;
string S;

// Functions
void input();
void solution();
void output();
int _max(int, int);
int maxDigitInString(int);

int main() {
	input();
	solution();
	output();

	return 0;
}

void input() {
	getline(cin, S);
	return;
}

void solution() {
	size = S.size();
	maxDigit = maxDigitInString(0);
	return;
}

void output() {
	cout << maxDigit << '\n';
	return;
}

int _max(int a, int b) {
	if (a > b)
		return a;
	return b;
}

int maxDigitInString(int index) {
	if (index == size - 1)
		return S[index] - '0';
	return _max(S[index] - '0', maxDigitInString(index + 1));
}
