#include <iostream>
#include <string>
using namespace std;

// Variables
int k, size;
string S;

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
	getline(cin, S);
	cin >> k;
}

void solution() {
	size = S.size();
	for (int i = 0; i < size; i++) {
		S[i] -= k;
		if (S[i] < 65)
			S[i] = 90 - (65 - S[i]) + 1;
	}
}

void output() {
	cout << S << '\n';
}
