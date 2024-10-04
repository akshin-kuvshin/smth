#include <iostream>
#include <string>

using namespace std;

// Variables
int _size,
	halfSize;
string S;

// Functions
void input();
void solution();
void output();
void deleteSameSymbols(int, string&);

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
	halfSize = _size / 2;
	deleteSameSymbols(0, S);
	
	return;
}

void output() {
	cout << S << '\n';	
	return;
}

void deleteSameSymbols(int index, string &str) {
	if (index == halfSize)
		return;
	
	if (str[index] == str[_size - index - 1]) {
		str.erase(index, 1);
		str.erase(_size - index - 2, 1);
		
		_size -= 2;
		halfSize--;
		
		deleteSameSymbols(index, str);
	} else deleteSameSymbols(index + 1, str);
	
	return;
}
