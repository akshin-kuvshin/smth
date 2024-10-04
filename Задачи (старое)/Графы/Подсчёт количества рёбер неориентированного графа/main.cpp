#include <iostream>
using namespace std;

// Constants
const int N_max = 1e2;

// Variables
int N,
	roots_amount;
bool roots[N_max + 5][N_max + 5];

// Functions
void input() {
	cin >> N;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			cin >> roots[i][j];
	return;
}

void solution() {
	for (int i = 0; i < N; i++)
		for (int j = i + 1; j < N; j++)
			if (roots[i][j])
				roots_amount++;
	return;
}

void output() {
	cout << roots_amount << '\n';
	return;
}

int main() {
	input();
	solution();
	output();
	
	return 0;
}
