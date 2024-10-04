#include <iostream>
using namespace std;

// Variables
int number;

// Functions
bool isPrime();

int main() {
	// Variables and input
	cin >> number;
	
	// Algorithm and output
	if (number == 1)
		cout << "-\n";
	else if (isPrime())
		cout << "YES" << endl;
	else
		cout << "NO" << endl;
	
	return 0;
}

bool isPrime() {
	for (int div = 2; div * div <= number; div++)
		if (number % div == 0)
			return false;
	return true;
}
