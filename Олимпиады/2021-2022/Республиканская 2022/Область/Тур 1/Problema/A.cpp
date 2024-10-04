#include <iostream>
using namespace std;

// Constants
const int N_max = 2e5;

// Variables
int N,
	A[N_max + 5],
	maxs[N_max + 5],
	element,
	amount,
	answer;

// Functions
void input();
void solution();
void output();
void get_maximums();
int _max(int, int);

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
	get_maximums();
	
	element = maxs[0];
	amount = 1;
	for (int i = 1; i < N; ++i) {
		if (maxs[i] == element)
			++amount;
		else {
			answer += amount - 1;
			
			element = maxs[i];
			amount = 1;
		}
	}
	
	answer += amount - 1;
	
	return;
}

void output() {
	cout << answer << '\n';
	return;
}

void get_maximums() {
	maxs[0] = A[0];
	for (int i = 1; i < N; ++i)
		maxs[i] = _max(maxs[i - 1], A[i]);
	return;
}

int _max(int num1, int num2) {
	return ( (num1 > num2) ? num1 : num2);
}
