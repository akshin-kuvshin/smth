#include <iostream>
using namespace std;

// Constants
const int width = 3;

// Variables
int n,
	num = 1;

int main() {
	// Input
	cin >> n;
	
	// Algorithm
	int array[2 * n + 1][2 * n + 1];
	array[n][n] = 0;
	for (int i = 1; i <= n; i++) {
		for (int j = 0, k = n - i, m = n + i - 1; j < 2 * i; j++, m--, num++)
			array[k][m] = num;
		for (int j = 0, k = n - i + 1, m = n - i; j < 2 * i; j++, k++, num++)
			array[k][m] = num;
		for (int j = 0, k = n + i, m = n - i + 1; j < 2 * i; j++, m++, num++)
			array[k][m] = num;
		for (int j = 0, k = n + i - 1, m = n + i; j < 2 * i; j++, k--, num++)
			array[k][m] = num;
	}
	
	// Output
	for (int i = 0; i < 2 * n + 1; i++) {
		for (int j = 0; j < 2 * n + 1; j++) {
			cout.width(width);
			cout << array[i][j] << ' ';
		}
		cout << '\n';
	}
	
	return 0;
}
