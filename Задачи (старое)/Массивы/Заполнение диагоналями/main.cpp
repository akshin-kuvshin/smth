#include <iostream>
using namespace std;

// Constants
const int width = 3;

// Variables
int n,
	m,
	num,
	diagonalsAmount;

int main() {
	// Input
	cin >> n >> m;
	
	// Algorithm
	int array[n][m];
	diagonalsAmount = n + m - 1;
	for (int iterator = 0; iterator < diagonalsAmount; iterator++)
		for (int i = 0, j = iterator, counter = 0; counter < n; i++, j--, counter++)
			if ( (i >= 0) and (i < n) and (j >= 0) and (j < m) ) {
				array[i][j] = num;
				num++;
			}
	
	// Output
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cout.width(width);
			cout << array[i][j] << ' ';
		}
		cout << '\n';
	}
	
	return 0;
}
