// ����� �������� ������� �� �������� DFS (�������!)
/* ������� �� ����� ������ ������� ���������� ����������������� ���� ���������. ������ ��� ���, �����, ���� �������� ��������,
 * �� ����� �������� ��� �������, ��� ���� ������� ����������. ����� �������� �� �������� DFS-�: ���������� ������ ��� ��������
 * ����, ��� �� ����� ������� ����������� �����. ����������: ����������� ����� - ������������ ������� i-���� ������� ������� A,
 * ������� ����� ����� i-���� �������� ������� B. ����� ���� ������� ������ ����������� �����, �� ������ ������������ ����������
 * ��������� ������� ������ ������ � ����� ������� � ���������� � ������ ������. �������, �� ����� �������� � ��������� �����������
 * � ������ ��� ��� ���������� ������ (���� ����������, ����������) ���� �� ������ d.
 * 
 * (a * b) % d == (a % d * b % d) % d
 * (a + b) % d == (a % d + b % d) % d
 */

// TODO
#include <iostream>
#include <vector>
#define LAST -1
using namespace std;

// Constants
const int MAX_SIZE = 5e5,
		  d = 998244353; // ���� � �������, ����� ���� �� ������ d

// Variables (�����)
int N,
	M,
	A[MAX_SIZE + 5],
	B[MAX_SIZE + 5];
long long answer;
// ����������, ������������ ������� ���� ���������
int order[MAX_SIZE + 5],
	id;
bool used[MAX_SIZE + 5];
vector<vector<int>> indexes;
// ���������� ��� DFS-�
int stack[MAX_SIZE + 5];

// Functions
void input();
void solution();
void output();
void get_indexes();
long long DFS(int);
long long _count(const int*, int);
vector<int>& ind_arr(int);
int _sz(int);
int ind(int, int);

int main() {
	input();
	solution();
	output();
	return 0;
}

void input() {
	cin >> N >> M;
	for (int i = 0; i < N; ++i)
		cin >> A[i];
	for (int j = 0; j < M; ++j)
		cin >> B[j];
	return;
}

void output() {
	cout << answer << '\n';
	return;
}

void solution() {
	get_indexes();
	answer = DFS(0);
	
	return;
}

// ������ used ����������, ��� �� ��� ������ �������� ������� �����.
// ������ order ����������, ��� ����� ������� � ������� indexes �������� ������� ���������
// � ���������� ���������.
// ���������� id ���������, ������� ���������� ��������� ��� �������,
// �.�. ����� ����� ������� ��������� ���������� �������.
// ������ indexes ������ ������� ���� ���������.
void get_indexes() {
	for (int i = 0; i < N; ++i)
		if (used[A[i]]) { // ������� ������ �����, ���������� ��� �� ��������.
			ind_arr(A[i]).push_back(i);
		} else { // ������ ����� �������
			used[A[i]] = true;
			order[A[i]] = id++;
			indexes.push_back(vector<int>(1, i));
		}
	return;
}

// ���������� ��� �������� ������ ����������� �����.
// ���������� k ��������, ��� �� �������� ����������� ����� ��� ������� k, �.�. ��� k-���� �������,
// �.�. ��� k-��� ������� ������� B.
int DFS(int k) {
	// ������� ������ ��������
	// ����� ���� �� ������� ����������� �����, ������� �������� �������, ���������� �����, ������ DFS ��� �� ��������.
	if (k == M) {
		int returning_value = _count(stack, k);
		return returning_value;
	}
	
	int current = B[k];
	long long ans = -1, // �.�. �� ��������
			  tmp;
	
	// ���� �� �������� ������ ����������� �����, �� �� ������ ������� ����� ��������� � ������ ������� A,
	// ������ ��� �������� �� ������ ������� �� ������ ����������� ����� ������ ������, �������� =>
	// ���� �� ����� ������ ����������� ������ ����� �� ��������� � ������, �� � ��� ��������� ������� �������
	// �� �������. ����� ����� ��������� � � ��������� ����������� ������, ������ ��� ������� �����
	// � ��������� ��������� � ������ A.
	if (!k) {
		int to = ind(current, 0);
		stack[0] = to;
		ans = DFS(k + 1);
	} else if (k == M - 1) {
		int to = ind(current, LAST);
		stack[M - 1] = to;
		ans = DFS(k + 1);
	} else
		for (int to : ind_arr(current)) {
			if (stack[k - 1] > to)
					continue; // ������ ��� i-��� ����������� ����� ������ ������� ������������� ������ (i + 1)-��.
			
			stack[k] = to;
			tmp = DFS(k + 1);
			
			if (ans == -1) // ������ �����������
				ans = tmp;
			else
				ans = (ans % d + tmp % d) % d;
		}
	
	return (ans == -1) ? 0 : ans; // ���� �� ��� ��� �� ��������, �� � ��������� ���������� ������������� ����������� �����
								  // �������� ���������� �������� ������ A ���, ��� ���������.
}

// ������� �������� ��������� ������� ��� ����������� ������������ ����������� �����.
// control_dots - ������� ����������� ����� � ������� A
long long _count(const int *control_dots, int _size) {
	// ������-��������� (�������)
	int _begin,
		_end,
		_new_begin,
		_new_end;
	
	// ���������
	int num_b, // ����������� ����� 1
		num_e; // ����������� ����� 2
	long long _ans = 1, // ����������� �������� ������������ ���� �����
			  _tmp;
	
	for (int i = 0; i + 1 < _size; ++i) {
		_new_begin = -1; // �� ����������
		_new_end = -1; // �� ����������
		
		_begin = control_dots[i];
		_end = control_dots[i + 1];
		num_b = A[_begin];
		num_e = A[_end];
		
		for (int k = _begin + 1; k < _end; ++k)
			if (A[k] == num_b) {
				_new_end = k;
				break;
			}
		for (int m = _end - 1; m > _begin; --m)
			if (A[m] == num_e) {
				_new_begin = m;
				break;
			}
		
		// ���� ���-�� �� ��������, �� ������� ������ �� ����, ������
		// �������� � �������� ���������.
		_new_begin = (_new_begin == -1) ? _begin : _new_begin;
		_new_end = (_new_end == -1) ? _end : _new_end;
		
		// ��� ����� ���������� ����� ������������ ������� ����� ������ ��������� �������.
		if (_new_begin >= _new_end)
			return 0;
		
		_tmp = _new_end - _new_begin;
		_ans = ( (_ans % d) * (_tmp % d) ) % d;
	}
	
	return _ans;
}

vector<int>& ind_arr(int elem) {
	return indexes[order[elem]];
}

int _sz(int elem) {
	return ind_arr(elem).size();
}

int ind(int elem, int i) {
	if (i == LAST)
		return ind_arr(elem)[_sz(elem) - 1];
	return ind_arr(elem)[i];
}
