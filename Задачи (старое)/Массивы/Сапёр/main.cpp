#include <iostream>
using namespace std;

// Constants
const int nMax = 32,
          mMax = 32,
		  wMax = 1e3;

// Variables
int n,
    m,
    field[nMax][mMax],
    w,
    wX[wMax],
    wY[wMax];

// Functions
void input();
void bombsInput();
void solution();
void setBombs();
void bombsCounting(int, int);
void output();

int main() {
	input();
	solution();
	output();
	return 0;
}

void input() {
	cin >> n >> m >> w;
	bombsInput();
}

void bombsInput() {
	for (int i = 0; i < w; i++) {
		cin >> wX[i] >> wY[i];
		wX[i]--;
		wY[i]--;
	}
}

void solution() {
	setBombs();
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (field[i][j] == -1)
				continue;
			bombsCounting(i, j);
		}
	}
}

void setBombs() {
	for (int i = 0; i < w; i++)
		field[wX[i]][wY[i]] = -1;
}

void bombsCounting(int i, int j) {
	if ( (i != 0) and (field[i - 1][j] == -1) ) {
		field[i][j]++;
	} if ( (i != n - 1) and (field[i + 1][j] == -1) ) {
		field[i][j]++;
	} if ( (j != 0) and (field[i][j - 1] == -1) ) {
		field[i][j]++;
	} if ( (j != m - 1) and (field[i][j + 1] == -1) ) {
		field[i][j]++;
	} if ( (i != 0) and (j != 0) and (field[i - 1][j - 1] == -1) ) {
		field[i][j]++;
	} if ( (i != 0) and (j != m - 1) and (field[i - 1][j + 1] == -1) ) {
		field[i][j]++;
	} if ( (i != n - 1) and (j != 0) and (field[i + 1][j - 1] == -1) ) {
		field[i][j]++;
	} if ( (i != n - 1) and (j != m - 1) and (field[i + 1][j + 1] == -1) ) {
		field[i][j]++;
	}
}

void output() {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (field[i][j] == -1)
				cout << "* ";
			else
				cout << field[i][j] << ' ';
		}
		cout << '\n';
	}
}
