#include <iostream>
using namespace std;

// Constants
const int sizeMax = 1e6;

// Variables
int size,
	array[sizeMax + 5],
	_max;

// Functions
void input();
void solution();
void output();
int arrayMax();

int main() {
	input();
	solution();
	output();
	
	return 0;
}

void input() {
	cin >> size;
	for (int i = 0; i < size; i++)
		cin >> array[i];
}

void solution() {
	_max = arrayMax();
}

void output() {
	if (size == 0)
		cout << "-\n";
	else
		cout << _max << '\n';
}

int arrayMax() {
	int answer = array[0];
	for (int i = 0; i < size; i++)
		if (answer < array[i])
			answer = array[i];
	return answer;
}
