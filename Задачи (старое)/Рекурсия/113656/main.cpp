#include <iostream>
#include <string>
using namespace std;

// Variables
int _size;
bool isEvenSize;
string startS,
	   endS;

// Functions
void input();
void solution();
void output();
string addEvenBrackets(int);
string addOddBrackets(int);

int main() {
	input();
	solution();
	output();
	
	return 0;
}

void input() {
	getline(cin, startS);
	return;
}

void solution() {
	_size = startS.size();
	isEvenSize = !(_size % 2);
	
	if (isEvenSize)
		endS = addEvenBrackets(0);
	else
		endS = addOddBrackets(0);
	
	return;
}

void output() {
	cout << endS << '\n';
	return;
}

string addEvenBrackets(int _iterator) {
	if (_size == 2)
		return startS;
	
	if (_iterator == _size - 1)
		return startS.substr(_iterator, 1);
	else if (_iterator < _size / 2 - 1)
		return startS.substr(_iterator, 1) + "(" + addEvenBrackets(_iterator + 1);
	else if (_iterator == _size / 2 - 1)
		return startS.substr(_iterator, 1) + addEvenBrackets(_iterator + 1);
	else
		return startS.substr(_iterator, 1) + ")" + addEvenBrackets(_iterator + 1);
}

string addOddBrackets(int _iterator) {
	if (_size == 1)
		return startS;
	
	if (_iterator == _size - 1)
		return startS.substr(_iterator, 1);
	else if (_iterator < (_size - 1) / 2)
		return startS.substr(_iterator, 1) + "(" + addOddBrackets(_iterator + 1);
	else
		return startS.substr(_iterator, 1) + ")" + addOddBrackets(_iterator + 1);
}
