#include <iostream>
#define dot pair<int, int>
#define x first
#define y second
using namespace std;

// Constants
const int MAX_SIZE = 1e6;

// Variables
int dots_number;
dot dots[MAX_SIZE + 5];

int shell_size;
dot shell[MAX_SIZE + 5];

// Functions
void input();
void solution();
void output();
int get_cr_pr(int, int, int, int);
int d_sqr(dot, dot);

int main() {
	input();
	solution();
	output();
	return 0;
}

void input() {
	cin >> dots_number;
	for (int i = 0; i < dots_number; ++i)
		cin >> dots[i].x >> dots[i].y;
	return;
}

void solution() {
	// ПОИСК НАЧАЛЬНОЙ ТОЧКИ (самой левой из самых нижних).
	// После поиска нужная точка будет стоять в dots[0].
	for (int i = 1; i < dots_number; ++i)
		if (dots[i].y < dots[0].y) // Нашли точку ниже...
			swap(dots[0], dots[i]);
		else if (dots[i].y == dots[0].y and dots[i].x < dots[0].x) // или на том же уровне, но левее
			swap(dots[0], dots[i]);
	/* cout << dots[0].x << ' ' << dots[0].y << '\n';
	system("pause"); */
	
	shell[shell_size++] = dots[0];
	
	do {
		dot current = shell[shell_size - 1]; // последняя добавленная
		dot asp = dots[0]; // "кандидат"
		
		for (int i = 1; i < dots_number; ++i) {
			if (current == asp) {
				asp = dots[i];
				continue;
			}
			
			int cr_pr = get_cr_pr(asp.x - current.x,
								  asp.y - current.y,
								  dots[i].x - current.x,
								  dots[i].y - current.y);
			
			// Если cr_pr == 0, то current, asp и dots[i] лежат на одной прямой.
			// Из пары кандидатов подходит тот, который дальше от последней добавленной в shell точки
			// (чтобы второй кандидат лежат на прямой => на границе оболочки =>
			// => оболочка будет задаваться меньшим количеством точек).
			if (cr_pr == 0) {
				if (d_sqr(current, dots[i]) > d_sqr(current, asp)) {
					asp = dots[i];
				}
			}
			// dots[i] лежит ниже прямой current-asp =>
			// => dots[i] лучше, чем asp.
			else if (cr_pr < 0) {
				asp = dots[i];
			}
		}
		
		shell[shell_size++] = asp;
	} while (shell[shell_size - 1] != dots[0]);
	
	return;
}

void output() {
	// Последний элемент не берём, потому что он равен первому
	// (цикл в solution() остановился, когда shell[0] == shell[shell_size - 1])
	cout << shell_size - 1 << '\n';
	for (int i = 0; i < shell_size - 1; ++i)
		cout << shell[i].x << ' ' << shell[i].y << '\n';
	return;
}

// Находит косое произведение [a, b], где:
// a(ax, ay)
// b(bx, by)
int get_cr_pr(int ax, int ay, int bx, int by) {
	return ax * by - bx * ay;
}

// Возвращает квадрат расстояния между точками A и B.
int d_sqr(dot A, dot B) {
	return (A.x - B.x) * (A.x - B.x) + (A.y - B.y) * (A.y - B.y);
}
