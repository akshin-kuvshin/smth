#include <iostream>
#include <string>
using namespace std;

// Variables
int _size,
	digitsAmount;
string S;

// Functions
void input();
void solution();
void output();
int numberOfDigitsInString(int);

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
	_size = S.size();
	digitsAmount = numberOfDigitsInString(0);
	return;
}

void output() {
	cout << digitsAmount << '\n';
	return;
}

int numberOfDigitsInString(int index) {
	if (index == _size - 1)
		if ( (S[index] >= 48) and (S[index] <= 57) )
			return 1;
		else
			return 0;
	
	return ( ( (S[index] >= 48) and (S[index] <= 57) ) ? 1 : 0) + numberOfDigitsInString(index + 1);
}
