#include <iostream>
using namespace std;

// Constants
const char answer[2][5] = {"NO", "YES"};

// Variables
int x1,
	x2,
	n;

void input() {
	cin >> x1 >> x2 >> n;
}

bool solution() {
	return ( ( (x1 - x2) / 2 >= n) and (x1 % 2 == x2 % 2) );
}

void output() {
	cout << answer[solution()] << '\n';
}

int main() {
	input();
	output();
	
	return 0;
}
