#include <iostream>
#define x first
#define y second
using namespace std;

const int N_max = 1e6;

int N;
pair<int, int> vertexes[N_max + 5];
float S;

int _abs(int);
float get_square(pair<int, int>*, int);

int main() {
	cin >> N;
	for (int i = 0; i < N; ++i)
		cin >> vertexes[i].x >> vertexes[i].y;
	
	S = get_square(vertexes, N);
	
	cout << S << '\n';
	return 0;
}

int _abs(int number) {
	if (number < 0)
		return - number;
	return number;
}

float get_square(pair<int, int> *A, int sz) {
	int answer = 0;
	pair<int, int> vect1,
				   vect2;
	for (int i = 1; i < sz - 1; ++i) {
		vect1 = make_pair(A[i].x - A[0].x, A[i].y - A[0].y);
		vect2 = make_pair(A[i + 1].x - A[0].x, A[i + 1].y - A[0].y);
		answer += vect1.x * vect2.y - vect1.y * vect2.x;
	}
	return _abs(answer) / 2.;
}
