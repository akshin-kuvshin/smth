#include <iostream>
#include <algorithm>
using namespace std;

// Constants
const int N_max = 1e6;

// Variables
int N,
	A[N_max + 5];

// Functions
bool comparer(int, int);

int main() {
	// Input
	cin >> N;
	for (int i = 0; i < N; i++)
		cin >> A[i];
	
	// Solution
	sort(A, A + N, comparer);
	
	// Output
	for (int i = 0; i < N; i++)
		cout << A[i] << ' ';
	cout << '\n';
	
	return 0;
}

bool comparer(int a, int b) {
	return (a > b);
}
