#include <iostream>
using namespace std;

// Variables
int number;
double answer;

// Functions
void input();
void solution();
void output();
double _sqrt(int);
double _abs(double);
int bestRootFinding(int, double*, int);

int main() {
	input();
	solution();
	output();
	
	return 0;
}

void input() {
	cin >> number;
}

void solution() {
	if (number == 0)
		return;
	answer = _sqrt(number);
}

void output() {
	cout << answer << '\n';
}

double _sqrt(int num) {
	int a = 0;
	
	for (; a * a <= num; a++);
	a--;
	
	int b = num - a * a;
	
	double c[2] = {a + b / (2. * a),
		   		   a + b / (2. * a + 1)};
	
	if (_abs(num - c[0] * c[0]) < _abs(num - c[1] * c[1]))
		return c[0];
	return c[1];
}

double _abs(double num) {
	if (num >= 0)
		return num;
	return -num;
}

// Нахождение того корня, разность между числом и квадратом которого
// минимальна, т.е. нахождение наиболее точного корня.
int bestRootFinding(int num, double *array, int sz) {
	int bestElementIndex = 0;
	double minAbs = _abs(num - array[0] * array[0]);
	
	for (int i = 0; i < sz; i++)
		if (_abs(num - array[i] * array[i]) < minAbs) {
			minAbs = _abs(num - array[i] * array[i]);
			bestElementIndex = i;
		}
	
	return bestElementIndex;
}
