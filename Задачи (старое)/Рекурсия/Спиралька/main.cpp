#include <iostream>
using namespace std;

// Constants
const int Nmax = 10;

// Variables
int N,
	array[Nmax + 5][Nmax + 5];

// Functions
void input();
void solution();
void output();
void fillSpiral(int, int, int, int, int, int, int, char);

int main() {
	input();
	solution();
	output();
	
	return 0;
}

void input() {
	cin >> N;
	return;
}

void solution() {
	fillSpiral(0, N, 0, N, 0, 0, 1, 'r');
	return;
}

void output() {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++)
			cout << array[i][j] << ' ';
		cout << '\n';
	}
	return;
}

void fillSpiral(int startX, int endX, int startY, int endY, int i, int j, int index, char dir) {
	if (index == N * N) {
		array[i][j] = index;
		return;
	}
	
	array[i][j] = index;
	if (dir == 'r') {
		if (j == endY - 1)
			fillSpiral(startX + 1, endX, startY, endY, i + 1, j, index + 1, 'd');
		else
			fillSpiral(startX, endX, startY, endY, i, j + 1, index + 1, 'r');
	} else if (dir == 'd') {
		if (i == endX - 1)
			fillSpiral(startX, endX, startY, endY - 1, i, j - 1, index + 1, 'l');
		else
			fillSpiral(startX, endX, startY, endY, i + 1, j, index + 1, 'd');
	} else if (dir == 'l') {
		if (j == startY)
			fillSpiral(startX, endX - 1, startY, endY, i - 1, j, index + 1, 'u');
		else
			fillSpiral(startX, endX, startY, endY, i, j - 1, index + 1, 'l');
	} else {
		if (i == startX)
			fillSpiral(startX, endX, startY + 1, endY, i, j + 1, index + 1, 'r');
		else
			fillSpiral(startX, endX, startY, endY, i - 1, j, index + 1, 'u');
	}
}
