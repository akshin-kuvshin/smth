#include <iostream>
using namespace std;

// Constants
const int N_max = 1e2;

// Variables
int N,
	costs[N_max + 5],
	min_costs[N_max + 5],
	_ans;

// Functions
void input();
void solution();
void output();
void get_min_costs();

int main() {
	input();
	solution();
	output();
	return 0;
}

void input() {
	cin >> N;
	for (int i = 1; i <= N; ++i)
		cin >> costs[i];
	return;
}

void solution() {
	get_min_costs();
	_ans = min_costs[0];
	return;
}

void output() {
	cout << _ans << '\n';
	return;
}

void get_min_costs() {
	min_costs[N - 1] = costs[N - 1] + costs[N];
	min_costs[N] = costs[N];
	
	for (int i = N - 2; i >= 0; --i)
		min_costs[i] = costs[i] + min(min_costs[i + 1], min_costs[i + 2]);
	
	return;
}
