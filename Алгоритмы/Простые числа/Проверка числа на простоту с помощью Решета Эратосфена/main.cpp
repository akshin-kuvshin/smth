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
	if (num == 1)
		cout << "-\n";
	else if (!primes[num])
		cout << "YES\n";
	else
		cout << "NO\n";
	
	return 0;
}

// ����� �� ���������� �������� �������,
// �� false ������, ��� ����� �������
// ��� ��� �� ���� ��������� �� �� �����;
// true ������, ��� ����� ��� ����������,
// ��� ���������. ��� ������ ������������
// �� �� �����.
void eratosthenesSieve() {
	for (int i = 2; i <= num; i++)
		if (!primes[i])
			if (i * i <= num)
				for (int j = i * i; j <= num; j += i)
					primes[j] = true;
}
