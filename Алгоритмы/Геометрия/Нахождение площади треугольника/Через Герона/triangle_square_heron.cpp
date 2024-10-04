#include <iostream>
#include <cmath>
#define dot pair<int, int>
#define x first
#define y second
using namespace std;

// Variables
dot A,
	B,
	C;
int AB_sqr,
	BC_sqr,
	AC_sqr;
double square;

// Functions
void input();
void solution();
void output();
int get_length_sqr(dot, dot);
double get_square(int, int, int);

int main() {
	input();
	solution();
	output();
	return 0;
}

void input() {
	cin >> A.x >> A.y;
	cin >> B.x >> B.y;
	cin >> C.x >> C.y;
	return;
}

void solution() {
	AB_sqr = get_length_sqr(A, B);
	BC_sqr = get_length_sqr(B, C);
	AC_sqr = get_length_sqr(A, C);
	
	square = get_square(AB_sqr, BC_sqr, AC_sqr);
	return;
}

void output() {
	cout << square << '\n';
	return;
}

int get_length_sqr(dot N, dot M) {
	return ( (N.x - M.x) * (N.x - M.x) + (N.y - M.y) * (N.y - M.y) );
}

// ѕоигралс€ с формулой √ерона, чтобы переход к нехорошему типу double
// осуществл€лс€ только в самом конце - при извлечении корн€.
// ¬ исходной формуле √ерона нам бы пришлось прибегнуть к нему
// уже при вычислении сторон треугольника.
double get_square(int a_sqr, int b_sqr, int c_sqr) {
	return 0.25 * sqrt( (a_sqr + b_sqr + c_sqr) * (a_sqr + b_sqr + c_sqr)
					   - 2 * (a_sqr * a_sqr + b_sqr * b_sqr + c_sqr * c_sqr) );
}
