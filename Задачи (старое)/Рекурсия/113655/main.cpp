#include <iostream>
#include <string>
using namespace std;

// Variables
int _size;
bool areWeNeedStars;
string startS, endS;

// Functions
void input();
void solution();
void output();
string addStars(int);

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
	
	if (_size != 1) {
		areWeNeedStars = true;
		endS = addStars(0);
	}
	
	return;
}

void output() {
	cout << (areWeNeedStars ? endS : startS) << '\n';
	return;
}

string addStars(int index) {
	if (index == _size - 1)
		return startS.substr(index, 1);
	return startS.substr(index, 1) + "*" + addStars(index + 1);
}
