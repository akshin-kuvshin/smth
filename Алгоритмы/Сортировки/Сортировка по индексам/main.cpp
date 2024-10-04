#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

// Constants
const int N_max = 1e6;

// Variables
int N,
	indexes[N_max + 5];
string A[N_max + 5];

// Functions
bool comparer(int, int);

int main() {
	// Input
	cin >> N;
	for (int i = 0; i < N; i++)
		cin >> A[i];
	
	// Solution
	for (int i = 0; i < N; i++)
		indexes[i] = i;
	sort(indexes, indexes + N, comparer);
	
	// Output
	for (int i = 0; i < N; i++)
		cout << A[indexes[i]] << '\n';
	
	return 0;
}

bool comparer(int a, int b) {
	return (A[a].size() < A[b].size());
}
