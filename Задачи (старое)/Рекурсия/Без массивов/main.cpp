#include <iostream>
using namespace std;

// Variables
int N;

// Functions
void reverse_sequence_output(int, int);

int main() {
	// Input
	cin >> N;
	
	// Solution and output
	reverse_sequence_output(0, N);
	cout << '\n';
	
	return 0;
}

void reverse_sequence_output(int index, int _size) {
	if (index == _size)
		return;
	
	int number;
	cin >> number;
	reverse_sequence_output(index + 1, _size);
	cout << number << ' ';
	return;
}
