/* F = 0,
   L = 90,
   B = 180,
   R = 270,
   LF = (0, 90),
   LB = (90, 180),
   RB = (180, 270),
   RF = (270, 360). */

#include <iostream>
#include <cmath>
#define x first
#define y second
using namespace std;

// Constants
const int MAX_SIZE = 1e5;
const double PI = 3.1415926535,
			 d = 1e-5;

// Variables
int N;
pair<int, int> A[MAX_SIZE + 5], // точки
			   current, // точка
			   from, // вектор
			   to; // вектор
double angle;

// Functions
void input();
void solution();
void detect_location(pair<int, int>, pair<int, int>);
bool _equal(double, double);

int main() {
	input();
	solution();
	return 0;
}

void input() {
	cin >> N;
	for (int i = 0; i < N; ++i)
		cin >> A[i].x >> A[i].y;
	return;
}

void solution() {
	current = make_pair(0, 0);
	from = make_pair(1, 0);
	
	for (int i = 0; i < N; ++i) {
		to = make_pair(A[i].x - current.x, A[i].y - current.y);
		
		detect_location(from, to);
		
		current = A[i];
		from = to;
	}
	
	return;
}

void detect_location(pair<int, int> vector1, pair<int, int> vector2) {
	int sc_pr = vector1.x * vector2.x + vector1.y * vector2.y, // cos
		cr_pr = vector1.x * vector2.y - vector2.x * vector1.y; // sin
	double len1 = sqrt(vector1.x * vector1.x + vector1.y * vector1.y),
		   len2 = sqrt(vector2.x * vector2.x + vector2.y * vector2.y);
	
	double cos = sc_pr / (len1 * len2),
		   sin = cr_pr / (len1 * len2);
	
	if (_equal(cos, 1) and _equal(sin, 0))
		cout << "F ";
	else if (cos > 0 and sin > 0)
		cout << "LF ";
	else if (_equal(cos, 0) and _equal(sin, 1))
		cout << "L ";
	else if (cos < 0 and sin > 0)
		cout << "LB ";
	else if (_equal(cos, -1) and _equal(sin, 0))
		cout << "B ";
	else if (cos < 0 and sin < 0)
		cout << "RB ";
	else if (_equal(cos, 0) and _equal(sin, -1))
		cout << "R ";
	else
		cout << "RF ";
	
	return;
}

bool _equal(double num1, double num2) {
	return abs(num1 - num2) < d;
}
