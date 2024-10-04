#include <iostream>
using namespace std;

// Constants
const int N_max = 1e2;

// Variables
int N,
	S,
	near_vertexes_amount;
bool graph[N_max + 5][N_max + 5];

// Variables for BFS
int head,
	tail,
	q[N_max + 5],
	selected;
bool used[N_max + 5];

// Functions
void bfs() {
	q[tail++] = S;
	used[S] = true;
	
	while (head != tail) {
		selected = q[head++];
		
		for (int i = 0; i < N; ++i) {
			if (selected == i)
				continue;
			if (graph[selected][i] and !used[i]) {
				q[tail++] = i;
				used[i] = true;
			}
		}
	}
	
	return;
}

void input() {
	cin >> N >> S;
	for (int i = 0; i < N; ++i)
		for (int j = 0; j < N; ++j)
			cin >> graph[i][j];
	return;
}

void solution() {
	S--;
	
	bfs();
	return;
}

void output() {
	cout << near_vertexes_amount << '\n';
	return;
}

int main() {
	input();
	solution();
	output();
	return 0;
}

