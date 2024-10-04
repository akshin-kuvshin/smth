#include <iostream>
using namespace std;

// Constants
const int subtests_max = 50,
		  N_max = 50;

// Variables
int subtests_amount,
	N,
	K,
	data[N_max + 5][N_max + 5][4][2],
/* В этом массиве первые два индекса - координаты клетки,
 * третий индекс - количество неиспользованных поворотов (начинается с K
 * и постепенно уменьшается с каждым изменением направления),
 * четвёртый индекс - направление, где 0 = движение вправо, 1 = движение вниз
 * (последний индекс нужен для подсчёта использованных поворотов).
 */
	answer,
	A[subtests_max + 5];
char field[N_max + 5][N_max + 5];

// Functions
bool check(int x, int y) {
	return (field[x][y] == '.');
}

void make_data_null(int x, int y) {
	for (int i = 0; i <= K; ++i)
		for (int j = 0; j < 2; ++j)
			data[x][y][i][j] = 0;
	return;
}

void fill_first_line() {
	bool is_stopped = false;
	for (int i = 1; i < N; ++i) {
		make_data_null(0, i);
		if (!check(0, i))
			is_stopped = true;
		if (!is_stopped)
			data[0][i][K][0] = 1;
	}
	return;
}

void fill_first_column() {
	bool is_stopped = false;
	for (int i = 1; i < N; ++i) {
		make_data_null(i, 0);
		if (!check(i, 0))
			is_stopped = true;
		if (!is_stopped)
			data[i][0][K][1] = 1;
	}
	return;
}

/* data[i][j - 1][0][0]
 * data[i][j - 1][0][1] - невозможно
 * data[i - 1][j][0][0] - невозможно
 * data[i - 1][j][0][1]
 * data[i][j - 1][1..K][0]
 * data[i][j - 1][1..K][1]
 * data[i - 1][j][1..K][0]
 * data[i - 1][j][1..K][1]
 */

void fill_other_data() {
	for (int i = 1; i < N; ++i)
		for (int j = 1; j < N; ++j) {
			if ( (i == N - 1) and (j == N - 1) )
				return;
			
			make_data_null(i, j);
			
			if (check(i, j)) {				
				data[i][j][0][0] += data[i][j - 1][0][0];
				data[i][j][0][1] += data[i - 1][j][0][1];
				
				for (int t = 1; t <= K; ++t) {
					data[i][j][t][0] += data[i][j - 1][t][0];
					data[i][j][t - 1][0] += data[i][j - 1][t][1];
					data[i][j][t - 1][1] += data[i - 1][j][t][0];
					data[i][j][t][1] += data[i - 1][j][t][1];
				}
			}
		}
	return;
}

/* data[N - 1][N - 2][0][0]
 * data[N - 1][N - 2][0][1] - невозможно
 * data[N - 2][N - 1][0][0] - невозможно
 * data[N - 2][N - 1][0][1]
 * data[N - 1][N - 2][1..K][0]
 * data[N - 1][N - 2][1..K][1]
 * data[N - 2][N - 1][1..K][0]
 * data[N - 2][N - 1][1..K][1]
 */

int get_answer() {
	int _ans = 0;
	
	_ans += data[N - 1][N - 2][0][0];
	_ans += data[N - 2][N - 1][0][1];
	
	for (int t = 1; t <= K; ++t) {
		_ans += data[N - 1][N - 2][t][0];
		_ans += data[N - 1][N - 2][t][1];
		_ans += data[N - 2][N - 1][t][0];
		_ans += data[N - 2][N - 1][t][1];
	}
	
	return _ans;
}

void dynamic_programming() {
	fill_first_line();
	fill_first_column();
	fill_other_data();
	answer = get_answer();
	return;
}

void input() {
	cin >> N >> K;
	for (int i = 0; i < N; ++i)
		for (int j = 0; j < N; ++j)
			cin >> field[i][j];
	return;
}

void solution() {
	dynamic_programming();
	return;
}

void output(int index) {
	A[index] = answer;
	return;
}

int main() {
	// Input
	cin >> subtests_amount;
	
	// Solution
	for (int i = 0; i < subtests_amount; ++i) {
		input();
		solution();
		output(i);
	}
	
	// Output
	for (int i = 0; i < subtests_amount; ++i)
		cout << A[i] << '\n';
	
	return 0;
}
