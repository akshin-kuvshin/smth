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
	answers[T_max + 5];
char field[N_max + 5][N_max + 5];

// Variables for BFS
int head,
	tail,
	ways_amount;
location q[N_max * N_max + 5],
		 selected;

// Functions
location make_location(int _i, int _j, int _changes_amount, char _direction) {
	location Location;
	Location.i = _i;
	Location.j = _j;
	Location.changes_amount = _changes_amount;
	Location.direction = _direction;
	return Location;
}

int bfs_algorithm() {
	// Input
	cin >> N >> K;
	for (int i = 0; i <= N + 1; i++)
		for (int j = 0; j <= N + 1; j++)
			if ( (i == 0) or (i == N + 1) or (j == 0) or (j = N + 1) )
				field[i][j] = 'H';
			else
				cin >> field[i][j];
	
	// Solution
	head = tail = ways_amount = 0;
	
	if (field[0][1] == '.')
		q[tail++] = make_location(0, 1, K, 'R');
	if (field[1][0] == '.')
		q[tail++] = make_location(1, 0, K, 'D');
	
	while (head != tail) {
		selected = q[head++];
		
		if ( (selected.i == N - 1) and (selected.j == N - 1) ) {
			ways_amount++;
			continue;
		}
		
		if (selected.direction == 'R') {
			if (field[selected.i][selected.j + 1] == '.')
				q[tail++] = make_location(selected.i, selected.j + 1, selected.changes_amount, 'R');
			if (selected.changes_amount and (field[selected.i + 1][selected.j] == '.') )
				q[tail++] = make_location(selected.i + 1, selected.j, selected.changes_amount - 1, 'D');
		} else {
			if (field[selected.i + 1][selected.j] == '.')
				q[tail++] = make_location(selected.i + 1, selected.j, selected.changes_amount, 'D');
			if (selected.changes_amount and (field[selected.i][selected.j + 1] == '.') )
				q[tail++] = make_location(selected.i, selected.j + 1, selected.changes_amount - 1, 'R');
		}
	}
	
	// Output
	return ways_amount;
}

void input() {
	cin >> T;
	return;
}

void solution() {
	for (int i = 0; i < T; i++)
		answers[i] = bfs_algorithm();
	return;
}

void output() {
	for (int i = 0; i < T; i++)
		cout << answers[i] << '\n';
	return;
}

int main() {
	input();
	solution();
	output();
	
	return 0;
}
