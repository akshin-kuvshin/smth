#include <iostream>
#include <algorithm>
using namespace std;

// Constants
const int SIZE = 3;

// Variables
int numbers[SIZE + 5],
	answer;

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
	for (int i = 0; i < SIZE; ++i)
		cin >> numbers[i];
	return;
}

void solution() {
	sort(numbers, numbers + SIZE);
	
	answer += 2 * numbers[1];
	numbers[2] -= numbers[1];
	numbers[1] = 0;
	
	if (numbers[2])
		++answer;
	
	answer += numbers[0];
	
	if (numbers[2] < numbers[0])
		answer += numbers[2];
	else
		answer += numbers[0];
	
	return;
}

void output() {
	cout << answer << '\n';
	return;
}
