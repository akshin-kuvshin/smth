#include <iostream>
using namespace std;

// Constants
const int numMax = 1e6;

// Variables
int num;

// Functions
void input();
void solution();

int main() {
	input();
	solution();
	
	return 0;
}

void input() {
	cin >> num;
}

void solution() {
	for (int i = 1; i <= num; i++)
		if (num % i == 0)
			cout << i << ' ';
	cout << '\n';
}
