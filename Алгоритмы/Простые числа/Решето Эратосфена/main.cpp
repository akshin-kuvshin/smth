#include <iostream>
using namespace std;

// Constants
const int numMax = 1e6;

// Variables
int num;
bool primes[numMax + 5];

// Functions
void eratosthenesSieve();

int main() {
	// Input
	cin >> num;
	
	// Algorithm
	eratosthenesSieve();
	
	// Output
	for (int i = 2; i <= num; i++)
		if (!primes[i])
			cout << i << ' ';
	cout << '\n';
	
	return 0;
}

// ����� �� ���������� �������� �������,
// �� false ������, ��� ����� �������
// ��� ��� �� ���� ��������� �� �� �����;
// true ������, ��� ����� ��� ����������,
// ��� ���������. ��� ������ ������������
// �� �� �����.
void eratosthenesSieve() {
	for (int i = 2; i * i <= num; i++)
		if (!primes[i])
			for (int j = i * i; j <= num; j += i)
					primes[j] = true;
	return;
}
