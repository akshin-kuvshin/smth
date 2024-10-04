#include <iostream>
#include <string>
using namespace std;

// Variables
int _size;
string startS,
	   endS;

// Functions
void input();
void solution();
void output();
string addMirrorString(int, bool);

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
	endS = addMirrorString(0, false);
	return;
}

void output() {
	cout << endS << '\n';
	return;
}

string addMirrorString(int _iterator, bool isMirror) {
	if (isMirror) {
		if (_iterator == 0)
			if (startS[_iterator] == '(')
				return ")";
			else
				return startS.substr(_iterator, 1);
		
		if (startS[_iterator] == '(')
			return ")" + addMirrorString(_iterator - 1, true);
		else
			return startS.substr(_iterator, 1) + addMirrorString(_iterator - 1, true);
	} else {
		if (_iterator == _size - 1)
			return startS.substr(_iterator, 1) + addMirrorString(_iterator, true);
		return startS.substr(_iterator, 1) + addMirrorString(_iterator + 1, false);
	}
}
