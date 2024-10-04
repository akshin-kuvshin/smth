#include <iostream>
using namespace std;

// Constants
const int N = 3,
		  letters_amount = 26;

// Variables
char lattice[N + 5][N + 5],
	 hypothesis[N + 5][N + 5];
int lattice_letters[letters_amount + 5],
	hypothesis_letters[letters_amount + 5],
	green_amount,
	yellow_amount;
bool used[N + 5][N + 5];

// Functions
int _min(int a, int b) {
	return ((a < b) ? a : b);
}

void get_green_amount() {
	for (int i = 0; i < N; ++i)
		for (int j = 0; j < N; ++j)
			if (lattice[i][j] == hypothesis[i][j]) {
				++green_amount;
				used[i][j] = true;
			}
	return;
}

void get_yellow_amount() {
	for (int i = 0; i < N; ++i)
		for (int j = 0; j < N; ++j)
			if (!used[i][j]) {
				++lattice_letters[lattice[i][j] - 'A'];
				++hypothesis_letters[hypothesis[i][j] - 'A'];
			}
	
	for (int i = 0; i < letters_amount; ++i)
		yellow_amount += _min(lattice_letters[i], hypothesis_letters[i]);
	
	return;
}

void input() {
	for (int i = 0; i < N; ++i)
		for (int j = 0; j < N; ++j)
			cin >> lattice[i][j];
	for (int i = 0; i < N; ++i)
		for (int j = 0; j < N; ++j)
			cin >> hypothesis[i][j];
	return;
}

void solution() {
	get_green_amount();
	get_yellow_amount();
	return;
}

void output() {
	cout << green_amount << '\n'
		 << yellow_amount << '\n';
	return;
}

int main() {
	input();
	solution();
	output();
	return 0;
}

