#include <iostream>
using namespace std;

// Constants
const int N_max = 6,
		  K_max = 6;

// Variables
int N,
	K,
	placement[N_max + 5];

// Functions
void array_output(int, int*);
void fill_first_placement(int, int*);
void find_placements(int, int, int*);

int main() {
	// Input
	cin >> N >> K;
	
	// Solution and output
	fill_first_placement(N, placement);
	find_placements(N, K, placement);
	
	return 0;
}

void array_output(int _size, int *_array) {
	for (int i = 0; i < _size; i++)
		cout << _array[i] << ' ';
	cout << '\n';
	
	return;
}

void fill_first_placement(int _size, int *_array) {
	for (int i = 0; i < _size; i++)
		_array[i] = 1;
	return;
}

void find_placements(int a, int b, int *_array) {
	array_output(a, _array);
	
	_array[a - 1]++;	
	for (int i = 1; i < a; i++)
		if (_array[i] == b + 1) {
			_array[i - 1]++;
			for (int j = i; j < a; j++)
				_array[j] = 1;
			
			if (_array[0] == b + 1)
				return;
			else if (_array[i - 1] == b + 1)
				i -= 2;
			else
				break;
			
		}
	
	if (_array[0] == b + 1)
		return;
	
	find_placements(a, b, _array);
	return;
}
