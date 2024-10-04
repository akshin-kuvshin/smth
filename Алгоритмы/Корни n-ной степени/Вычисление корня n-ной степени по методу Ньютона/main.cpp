#include <iostream>
using namespace std;

// Variables
int A, // ����������� ���������
	n; // ������� ������������ �����
double answer;

// Functions
void input();
void solution();
void output();
double _pow(double, int);
double _root(int, int);
double _abs(double);

int main() {
	input();
	solution();
	output();
	
	return 0;
}

void input() {
	cin >> A >> n;
}

void solution() {
	answer = _root(A, n);
}

void output() {
	cout << answer << '\n';
}

double _pow(double base, int pointer) {
	double k = 1; // ������������ ��������
	
	while (pointer != 0) {
		if (pointer % 2 == 0) {
			base *= base;
			pointer /= 2;
		} else {
			k *= base;
			pointer--;
		}
	}
	
	return k;
}

double _root(int base, int pointer) {
	double root = base / pointer, // ������ ����������� �����
		   eps = 1e-6; // �����������, �� ������� ����������� �����
	
	while (eps <= _abs(base - _pow(root, pointer) ) )
		// ������� ���� �� �������
		root = (root * (pointer - 1) + base / _pow(root, pointer - 1) ) / pointer;
	
	return root;
}

double _abs(double num) {
	if (num >= 0)
		return num;
	return -num;
}
