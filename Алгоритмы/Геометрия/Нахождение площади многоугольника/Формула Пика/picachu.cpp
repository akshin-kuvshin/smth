#include <iostream>
#define x first
#define y second
using namespace std;

const int N_max = 1e6;
const float eps = 1e-3;

int N,
	dots_on_edges,
	dots_inside;
pair<int, int> vertexes[N_max + 5];
float S_tmp,
	  S_ans;

int gcd_R(int, int);
int dots_on_segment(pair<int, int>, pair<int, int>);
float get_square(pair<int, int>*, int);

int main() {
	cin >> N;
	for (int i = 0; i < N; ++i)
		cin >> vertexes[i].x >> vertexes[i].y;
	vertexes[N] = vertexes[0];
	
	S_tmp = get_square(vertexes, N);
	
	dots_on_edges = N; // вершины многоугольника считаем отдельно
	for (int i = 0; i < N; ++i)
		dots_on_edges += dots_on_segment(vertexes[i], vertexes[i + 1]);
	
	dots_inside = S_tmp + 1. - dots_on_edges / 2. + 5 * eps;
	
	S_ans = dots_inside + dots_on_edges / 2. - 1;
	cout << S_ans << '\n';
	return 0;
}

int gcd_R(int num1, int num2) {
	return (num1 && num2) ? gcd_R(num2, num1 % num2) : (num1 | num2);
}

int dots_on_segment(pair<int, int> A, pair<int, int> B) {
	return gcd_R(abs(B.x - A.x), abs(B.y - A.y)) - 1;
}

float get_square(pair<int, int> *A, int sz) {
	int answer = 0;
	for (int i = 0; i < sz; ++i) {
		answer += A[i].x * A[i + 1].y;
		answer -= A[i].y * A[i + 1].x;
	}
	return abs(answer) / 2.;
}
