#include <iostream>
using namespace std;

// Variables
int A[] = {1, 5, 0, -9, 8};

// Functions
void bubbleSort(int*, int);

int main() {
	bubbleSort(A, 5);
	
	for (int i = 0; i < 5; i++)
		cout << A[i] << ' ';
	cout << '\n';
	
	return 0;
}

void bubbleSort(int *array, int size) {
	for (int i = 0; i < size - 1; i++)
		for (int j = i + 1; j < size; j++)
			if (array[i] > array[j]) {
				array[i] = array[i] ^ array[j];
				array[j] = array[i] ^ array[j];
				array[i] = array[i] ^ array[j];
			}
}
