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
	// ����� ��������� ����� (����� ����� �� ����� ������).
	// ����� ������ ������ ����� ����� ������ � dots[0].
	for (int i = 1; i < dots_number; ++i)
		if (dots[i].y < dots[0].y) // ����� ����� ����...
			swap(dots[0], dots[i]);
		else if (dots[i].y == dots[0].y and dots[i].x < dots[0].x) // ��� �� ��� �� ������, �� �����
			swap(dots[0], dots[i]);
	/* cout << dots[0].x << ' ' << dots[0].y << '\n';
	system("pause"); */
	
	shell[shell_size++] = dots[0];
	
	do {
		dot current = shell[shell_size - 1]; // ��������� �����������
		dot asp = dots[0]; // "��������"
		
		for (int i = 1; i < dots_number; ++i) {
			if (current == asp) {
				asp = dots[i];
				continue;
			}
			
			int cr_pr = get_cr_pr(asp.x - current.x,
								  asp.y - current.y,
								  dots[i].x - current.x,
								  dots[i].y - current.y);
			
			// ���� cr_pr == 0, �� current, asp � dots[i] ����� �� ����� ������.
			// �� ���� ���������� �������� ���, ������� ������ �� ��������� ����������� � shell �����
			// (����� ������ �������� ����� �� ������ => �� ������� �������� =>
			// => �������� ����� ���������� ������� ����������� �����).
			if (cr_pr == 0) {
				if (d_sqr(current, dots[i]) > d_sqr(current, asp)) {
					asp = dots[i];
				}
			}
			// dots[i] ����� ���� ������ current-asp =>
			// => dots[i] �����, ��� asp.
			else if (cr_pr < 0) {
				asp = dots[i];
			}
		}
		
		shell[shell_size++] = asp;
	} while (shell[shell_size - 1] != dots[0]);
	
	return;
}

void output() {
	// ��������� ������� �� ����, ������ ��� �� ����� �������
	// (���� � solution() �����������, ����� shell[0] == shell[shell_size - 1])
	cout << shell_size - 1 << '\n';
	for (int i = 0; i < shell_size - 1; ++i)
		cout << shell[i].x << ' ' << shell[i].y << '\n';
	return;
}

// ������� ����� ������������ [a, b], ���:
// a(ax, ay)
// b(bx, by)
int get_cr_pr(int ax, int ay, int bx, int by) {
	return ax * by - bx * ay;
}

// ���������� ������� ���������� ����� ������� A � B.
int d_sqr(dot A, dot B) {
	return (A.x - B.x) * (A.x - B.x) + (A.y - B.y) * (A.y - B.y);
}
