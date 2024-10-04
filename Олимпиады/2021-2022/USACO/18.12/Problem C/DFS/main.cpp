#include <iostream>
using namespace std;

// Structures
struct location {
	int i;
	int j;
	int changes_amount;
	char direction;
};

// Constants
const int T_max = 50,
		  N_max = 50;

// Variables
int T,
	N,
	K,
	answer,
	A[T_max + 5];
char field[N_max + 5][N_max + 5];
bool used[N_max + 5][N_max + 5];

// Functions
bool check(int x, int y) {
	return (field[x][y] == '.');
}

location make_location(int _i, int _j, int _changes_amount, char _direction) {
	location Loc;
	Loc.i = _i;
	Loc.j = _j;
	Loc.changes_amount = _changes_amount;
	Loc.direction = _direction;
	return Loc;
}

void dfs_algorithm(location selected) {
	if ( (selected.i == N) and (selected.j == N) ) {
		answer++;
		return;
	}

	used[selected.i][selected.j] = true;

	if (selected.direction == 'R') {
		if (check(selected.i, selected.j + 1))
			dfs_algorithm(make_location(selected.i, selected.j + 1, selected.changes_amount, 'R'));
		if (selected.changes_amount and check(selected.i + 1, selected.j))
			dfs_algorithm(make_location(selected.i + 1, selected.j, selected.changes_amount - 1, 'D'));
	} else {
		if (check(selected.i + 1, selected.j))
			dfs_algorithm(make_location(selected.i + 1, selected.j, selected.changes_amount, 'D'));
		if (selected.changes_amount and check(selected.i, selected.j + 1))
			dfs_algorithm(make_location(selected.i, selected.j + 1, selected.changes_amount - 1, 'R'));
	}

	used[selected.i][selected.j] = false;
	return;
}

void input() {
	cin >> N >> K;
	for (int i = 1; i <= N; ++i)
		for (int j = 1; j <= N; ++j)
			cin >> field[i][j];
	return;
}

void solution() {
	if (check(1, 2)) dfs_algorithm(make_location(1, 2, K, 'R'));
	if (check(2, 1)) dfs_algorithm(make_location(2, 1, K, 'D'));
	return;
}

void output(int index) {
	A[index] = answer;
	return;
}

int main() {
	// Input
	cin >> T;
	
	// Solution
	for (int i = 0; i < T; ++i) {
		answer = 0;
		
		input();
		solution();
		output(i);
	}
	
	// Output
	for (int i = 0; i < T; ++i)
		cout << A[i] << '\n';
	
	return 0;
}
