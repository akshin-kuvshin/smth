#include <iostream>
using namespace std;

// Constants
const int numMax = 1e6;

// Variables
int num;
bool divisors[numMax + 5];

// Functions
void divisorsFinding();

int main() {
	// Input
	cin >> num;
	
	// Algorithm
	divisorsFinding();
	
	// Output
	for (int i = 1; i <= num; i++)
		if (!divisors[i])
			cout << i << ' ';
	cout << '\n';
	
	return 0;
}

// В массиве divisors значение false
// соответствует числу, не являющемуся
// делителем заданного; true значит,
// что число является делителем
// заданного
void divisorsFinding() {
	for (int i = 2; i <= num; i++)
		if (num % i != 0)
			divisors[i] = true;
}
