#include <iostream>
#include <set>
#include <string>
using namespace std;

// Structures
struct Comparator {
	// �����������, ����� ����������� ��������� ���� ������������, � ���������
	// ������ ���������� �������� ������ �������� � ����������.
	bool operator() (const string &S1, const string &S2) {
		return S1.length() < S2.length();
	}
};

// Constants
const int N_max = 1e2;

// Variables
int N;
string A[N_max + 5];
multiset<string, Comparator> my_set;

// ����� ��������� multiset, ������ ��� ��� ������ ������ ���������� �����
// ��������� �� ���� (�.�. ���������� ������ �� ������ �����), � �����, ��������,
// ��� ������ "yana" � "maks" ����� ������� � ���������.
int main() {
	cin >> N;
	for (int i = 0; i < N; ++i)
		cin >> A[i];
	
	for (int i = 0; i < N; ++i)
		my_set.insert(A[i]);
	
	for (multiset<string>::iterator it = my_set.begin(); it != my_set.end(); ++it)
		cout << *it << ' ';
	cout << '\n';
	
	return 0;
}
