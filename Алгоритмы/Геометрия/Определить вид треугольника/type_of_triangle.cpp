/*
	-1 => ������������
	0 => �������������
	1 => �������������
*/

#include <iostream>
#include <algorithm>
#define dot pair<int, int>
#define x first
#define y second
using namespace std;

// Variables
int result;
dot A,
	B,
	C;
int lengthes_sqr[3],
    n,
    m,
    K;

// Functions
void input();
void solution();
void output();
int get_length_sqr(dot, dot);

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
	lengthes_sqr[0] = get_length_sqr(A, B);
	lengthes_sqr[1] = get_length_sqr(B, C);
	lengthes_sqr[2] = get_length_sqr(A, C);
	
	sort(lengthes_sqr, lengthes_sqr + 3); // � ������� �����������
	
	n = lengthes_sqr[0];
	m = lengthes_sqr[1];
	K = lengthes_sqr[2]; // ���������� ������� (K >= m >= n)
	
	// ����� �� ��������� ������������� ������������?
	// � ��� �������������?
	
	// �������� �� ������ ������� ���������
	if (n + m == K) // ��������� => �������������
		result = 0;
	else if (n + m < K) // ������������
		result = -1;
	else // �������������
		result = 1;
	
	return;
}

void output() {
	cout << result << '\n';
	return;
}

int get_length_sqr(dot N, dot M) {
	return ( (N.x - M.x) * (N.x - M.x) + (N.y - M.y) * (N.y - M.y) );
}
