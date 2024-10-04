#include <iostream>
using namespace std;

// Constants
const int N_max = 4e1,
		  numbers_amount = 3;

// Variables
int N,
	A[N_max + 5][numbers_amount + 5],
	_ans;

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
	return;
}

void solution() {
	A[1][0] = A[1][1] =  1;
	
	for (int i = 2; i <= N; ++i) {
		A[i][0] = A[i - 1][0] + A[i - 1][1] + A[i - 1][2];
		A[i][1] = A[i - 1][0];
		A[i][2] = A[i - 1][1];
	}
	
	_ans = A[N][0] + A[N][1] + A[N][2];
	
	return;
}

void output() {
	cout << _ans << '\n';
	return;
}
