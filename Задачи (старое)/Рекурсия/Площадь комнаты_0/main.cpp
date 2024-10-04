#include <iostream>
using namespace std;

// Constants
const int Nmax = 10;

// Variables
int N,
	x,
	y,
	roomArea;
char labyrinth[Nmax + 5][Nmax + 5];
bool checked[Nmax + 5][Nmax + 5];

// Functions
void input();
void solution();
void output();
int getRoomArea(int, int);

int main() {
	input();
	solution();
	output();
	
	return 0;
}

void input() {
	cin >> N;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			cin >> labyrinth[i][j];
	cin >> x >> y;
	
	return;
}

void solution() {
	x--;
	y--;
	
	roomArea = getRoomArea(x, y);
	
	return;
}

void output() {
	cout << roomArea << '\n';
	return;
}

int getRoomArea(int a, int b) {
	if ( (a == -1) or (b == -1) or (a == N) or (b == N) )
		return 0;
	if (labyrinth[a][b] == '*')
		return 0;
	if (checked[a][b])
		return 0;
	
	checked[a][b] = true;
	return 1 + getRoomArea(a + 1, b)
			 + getRoomArea(a, b + 1)
			 + getRoomArea(a - 1, b)
			 + getRoomArea(a, b - 1);
}
