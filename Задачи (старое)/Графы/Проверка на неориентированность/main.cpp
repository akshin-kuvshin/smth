#include <iostream>
using namespace std;

// Constants
const int N_max = 1e2;

// Variables
int N;
bool roots[N_max + 5][N_max + 5];
char answers[2][10] = {"NO\n", "YES\n"};

// Functions
void input() {
	cin >> N;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			cin >> roots[i][j];
	return;
}

bool solution() {
	for (int i = 0; i < N; i++) {
		if (roots[i][i])
			return false;
		for (int j = i + 1; j < N; j++)
			if (roots[i][j] != roots[j][i])
				return false;
	}
	return true;
}

void output() {
	cout << answers[solution()];
	return;
}

int main() {
	input();
	output();
	
	return 0;
}
