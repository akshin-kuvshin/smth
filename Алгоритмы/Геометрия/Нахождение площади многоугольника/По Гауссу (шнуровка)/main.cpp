#include <iostream>
#define x first
#define y second
using namespace std;

const int N_max = 1e6;

int N;
pair<int, int> A[N_max + 5];
float S;

int _abs(int);
int get_double_square(pair<int, int>*, int);

int main() {
	cin >> N;
	for (int i = 0; i < N; ++i)
		cin >> A[i].x >> A[i].y;
	A[N] = A[0];
	
	S = _abs(get_double_square(A, N)) / 2.;
	
	cout << S << '\n';
	return 0;
}

int _abs(int number) {
	if (number < 0)
		return - number;
	return number;
}

int get_double_square(pair<int, int> *vertexes, int sz) {
	int answer = 0;
	for (int i = 0; i < sz; ++i) {
		answer += vertexes[i].x * vertexes[i + 1].y;
		answer -= vertexes[i].y * vertexes[i + 1].x;
	}
	return answer;
}
