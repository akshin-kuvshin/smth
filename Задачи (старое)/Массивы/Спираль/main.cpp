#include <iostream>
using namespace std;

// Constants
const int Nmax = 50;

// Variables
int n,
	A[Nmax + 5][Nmax + 5],
	squaresAmount;

// Functions
void makingSquares();
void changingDiagonal();

int main() {
	// Input
	cin >> n;
	
	// Algorithm	
	makingSquares();
	changingDiagonal();
	
	// Output
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++)
			cout << A[i][j];
		cout << '\n';
	}
	
	return 0;
}

void makingSquares() {
	squaresAmount = n / 4 + 1 % (n % 4 + 1);
	for (int i = 0, j = 0, iterator = 0; iterator < squaresAmount; i += 2, j += 2, iterator++) {
		for (int k = i, m = j; m <= n - j - 1; m++)
			A[k][m] = 1;
		for (int k = i, m = n - j - 1; k <= n - i - 1; k++)
			A[k][m] = 1;
		for (int k = n - i - 1, m = n - j - 1; m >= j; m--)
			A[k][m] = 1;
		for (int k = n - i - 1, m = j; k >= i; k--)
			A[k][m] = 1;
	}
}

void changingDiagonal() {
	if (n == 1)
		return;
	
	A[1][0] = (A[1][0] ? 0 : 1);
	for (int i = 2, j = 1; i <= n / 2; i++, j++)
		A[i][j] = (A[i][j] ? 0 : 1);
	
	if (n % 4 == 0)
		A[n / 2][n / 2 - 1] = 0;
}
