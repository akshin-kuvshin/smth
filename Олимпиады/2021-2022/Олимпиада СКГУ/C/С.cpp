//#include <iostream> // закомментировать для файлового ввода
#include <fstream> // раскомментировать для файлового ввода
//#define fin cin // закомментировать для файлового ввода
//#define fout cout // закомментировать для файлового ввода
using namespace std;

// Constants
const int MAX_SIZE = 1e4;

// Variables
int M,
	N,
	Q,
	A[MAX_SIZE + 5][MAX_SIZE + 5],
	B[MAX_SIZE + 5][MAX_SIZE + 5],
	T[MAX_SIZE + 5][MAX_SIZE + 5],
	max_money[MAX_SIZE + 5][MAX_SIZE + 5],
	answer = -1;

// Functions
void input();
void solution();
void output();
void DFS(int, int, int);

int main() {
	input();
	solution();
	output();
	return 0;
}

void input() {
	ifstream fin("a.in"); // раскомментировать для файлового ввода
	fin >> M >> N >> Q;
	for (int i = 1; i <= M; ++i)
		for (int j = 1; j <= N; ++j)
			fin >> A[i][j] >> B[i][j] >> T[i][j];
	fin.close(); // раскомментировать для файлового ввода
	return;
}

void solution() {
	for (int i = 0; i < M; ++i)
		for (int j = 0; j < N; ++j)
			max_money[i][j] = -1;
	
	DFS(1, 1, Q);
	return;
}

void output() {
	ofstream fout("a.out"); // раскомментировать для файлового ввода
	fout << answer << '\n';
	fout.close(); // раскомментировать для файлового ввода
	return;
}

void DFS(int x, int y, int money) {
	if ( (x == M) and (y == N) ) { // <- крайний случай (хороший)
		answer = max(answer, money);
		return;
	} if ( (x > M) or (y > N) ) // <- плохой случай (ужасный)
		return;
	
	if (max_money[x][y] != -1) {
		if (money < max_money[x][y])
			return;
	} else max_money[x][y] = money;
	
	if (money >= A[x][y]) {
		DFS(x + 1, y, money - A[x][y] + T[x + 1][y]);
		DFS(x, y + 1, money - A[x][y] + T[x][y + 1]);
		DFS(x + 1, y + 1, money - A[x][y] + T[x + 1][y + 1]);
	} if (money >= B[x][y]) {
		DFS(x + 2, y, money - B[x][y] + T[x + 2][y]);
		DFS(x, y + 2, money - B[x][y] + T[x][y + 2]);
	}
	
	return;
}
