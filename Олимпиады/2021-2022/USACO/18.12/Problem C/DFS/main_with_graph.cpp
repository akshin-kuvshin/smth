#include <iostream>
#define NO_WAY 0
using namespace std;

// Constants
const int T_max = 50,
		  N_max = 50;

// Variables
int T,
	N,
	K,
	proiz,
	// В графе мы идём направо, если идём в вершину
	// с индексом 0, и идём вниз, если идём в вершину
	// с индексом 1.
	g[N_max * N_max + 5][2],
	A[T_max + 5],
	answer;
char field[N_max * N_max + 5];

// Functions
bool check(int x) {
	return (field[x] == '.');
}

void make_graph() {
	for (int i = 1; i <= proiz; ++i) {
		if (!check(i))
			continue;
		
		g[i][0] = g[i][1] = NO_WAY;
		
		// путь в клеточку справа
		if ( (i % N != 0) and check(i + 1))
			g[i][0] = i + 1;
		
		// путь в клеточку снизу
		if ( (i <= proiz - N) and check(i + N))
			g[i][1] = i + N;
	}
	return;
}

void dfs_algorithm(int num, int changes_amount, bool direction) {
	if (num == proiz) {
		answer++;
		return;
	}
	
	if (!direction) { // selected.direction == 'R'
		if (g[num][0])
			dfs_algorithm(g[num][0], changes_amount, direction);
		if (g[num][1] and changes_amount)
			dfs_algorithm(g[num][1], changes_amount - 1, !direction);
	} else { // selected.direction == true == 'D'
		if (g[num][0] and changes_amount)
			dfs_algorithm(g[num][0], changes_amount - 1, !direction);
		if (g[num][1])
			dfs_algorithm(g[num][1], changes_amount, direction);
	}
	
	return;
}

void input() {
	ios_base::sync_with_stdio(false);
	cin >> N >> K;
	proiz = N * N;
	for (int i = 1; i <= proiz; ++i) {
		ios_base::sync_with_stdio(false);
		cin >> field[i];
	}
	return;
}

void solution() {
	make_graph();
	
	if (check(2)) dfs_algorithm(2, K, false);
	if (check(1 + N)) dfs_algorithm(1 + N, K, true);
	return;
}

void output(int index) {
	A[index] = answer;
	return;
}

int main() {
	// Input
	ios_base::sync_with_stdio(false);
	cin >> T;
	
	// Solution
	for (int i = 0; i < T; ++i) {
		answer = 0;
		
		input();
		solution();
		output(i);
	}
	
	// Output
	for (int i = 0; i < T; ++i) {
		cout.tie(0);
		cout << A[i] << '\n';
	}
	
	return 0;
}
