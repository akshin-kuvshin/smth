#include <iostream>
#include <algorithm>
using namespace std;

// Constants
const int N_max = 1e5;

// Variables
int N,
	A[N_max + 5],
	sorted_A[N_max + 5],
	sum_A,
	sum_sorted,
	answer;

// Functions
void input();
void solution();
void output();
void copy_array(int *from, int *to, int _size);

int main() {
	input();
	solution();
	output();
	return 0;
}

void input() {
	cin >> N;
	for (int i = 0; i < N; ++i)
		cin >> A[i];
	return;
}

void solution() {
	copy_array(A, sorted_A, N);
	sort(sorted_A, sorted_A + N);
	
	sum_A = A[0];
	sum_sorted = sorted_A[0];
	for (int i = 1; i < N; ++i)
		if (sum_A == sum_sorted) {
			++answer;
			
			sum_A = A[i];
			sum_sorted = sorted_A[i];
		} else {
			sum_A += A[i];
			sum_sorted += sorted_A[i];
		}
	++answer;
	
	return;
}

void output() {
	cout << answer << '\n';
	return;
}

void copy_array(int *from, int *to, int _size) {
	for (int i = 0; i < _size; ++i)
		to[i] = from[i];
	return;
}
