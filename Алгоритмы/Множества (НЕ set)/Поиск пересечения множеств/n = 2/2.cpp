#include <iostream>
#include <set>
using namespace std;

// Constants
const int MAX_SIZE = 1e5;

// Variables
int N,
	A[MAX_SIZE + 5],
	K,
	B[MAX_SIZE + 5];

set<int> _union;

int _union_size,
	cross_size; // answer

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
	cin >> N;
	for (int i = 0; i < N; ++i)
		cin >> A[i];
	cin >> K;
	for (int j = 0; j < K; ++j)
		cin >> B[j];
	
	return;
}

void solution() {
	for (int i = 0; i < N; ++i)
		_union.insert(A[i]);
	for (int j = 0; j < K; ++j)
		_union.insert(B[j]);
	
	_union_size = _union.size();
	
	cross_size = N + K - _union_size;
	
	return;
}

void output() {
	cout << cross_size << '\n';
	return;
}

