// Алгоритм работает для чисел, амплитуда которых
// (разность между максимальным и минимальным) меньше
// 1e6.

#include <iostream>
using namespace std;

// Constants
const int N_max = 1e6,
		  counters_max = 1e6;

// Variables
int N,
	A[N_max + 5],
	_min,
	_max,
	counters_amount,
	counters[counters_max + 5];

// Functions
int min_in_array(int*, int);
int max_in_array(int*, int);
void countingSort(int*, int);

int main() {
	// Input
	cin >> N;
	for (int i = 0; i < N; i++)
		cin >> A[i];
	
	// Solution
	_min = min_in_array(A, N);
	_max = max_in_array(A, N);
	counters_amount = _max - _min + 1;
	countingSort(A, N);
	
	// Output
	for (int i = 0; i < N; i++)
		cout << A[i] << ' ';
	cout << '\n';
	
	return 0;
}

int min_in_array(int *array, int size) {
	int answer = array[0];
	for (int i = 1; i < size; i++)
		if (answer > array[i])
			answer = array[i];
	return answer;
}

int max_in_array(int *array, int size) {
	int answer = array[0];
	for (int i = 1; i < size; i++)
		if (answer < array[i])
			answer = array[i];
	return answer;
}

void countingSort(int *array, int size) {
	for (int i = 0; i < size; i++)
		counters[array[i] - _min]++;
	
	for (int i = _min, ind = 0; i <= _max; i++)
		for (int j = 0; j < counters[i - _min]; j++)
			array[ind++] = i;
	
	return;
}
