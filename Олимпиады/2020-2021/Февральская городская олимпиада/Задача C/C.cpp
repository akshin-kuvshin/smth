#include <iostream>
using namespace std;

// Constants
const int members_amount = 3,
		  N_max = 1e1,
		  time_max = 3e2;

// Variables
int N,
	times[N_max + 5][members_amount + 5],
	used_times[members_amount + 5],
	tasks_max,
	time_min = N_max * time_max + 5,
	time_tmp,
	stack[N_max + 5],
	top;

// Functions
void input();
void solution();
void output();
void dfs();
void check();
void cleaning();

int main() {
	input();
	solution();
	output();
	return 0;
}

void input() {
	cin >> N;
	for (int i = 0; i < N; ++i)
		for (int j = 0; j < members_amount; ++j)
			cin >> times[i][j];
	return;
}

void solution() {
	dfs();
	return;
}

void output() {
	cout << tasks_max << ' ' << time_min << '\n';
	return;
}

void dfs() {
	if (top == N)
		return;
	
	for (int i = 0; i < members_amount; ++i) {
		stack[top++] = i;
		check();
		dfs();
		--top;
	}
	
	return;
}

void check() {
	for (int k = 0; k < top; ++k) {
		used_times[stack[k]] += times[k][stack[k]];
		time_tmp += times[k][stack[k]];
	}
	
	for (int i = 0; i < members_amount; ++i)
		if (used_times[i] > time_max) {
			cleaning();
			return;
		}
	
	if (tasks_max < top) {
		tasks_max = top;
		time_min = time_tmp;
	}
	
	cleaning();
	return;
}

void cleaning() {
	for (int i = 0; i < members_amount; ++i)
		used_times[i] = 0;
	time_tmp = 0;
	return;
}
