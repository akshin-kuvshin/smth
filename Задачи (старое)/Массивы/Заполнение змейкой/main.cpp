#include <iostream>
using namespace std;

// Variables
int n, m, num;
bool isToRight = true;

int main() {
	// Input
	cin >> n >> m;
	int A[n][m];
	
	// Algorithm
	for (int i = 0; i < n; i++) {
		if (isToRight) {
			for (int j = 0; j < m; j++, num++)
				A[i][j] = num;
			isToRight = false;
		} else {
			for (int j = m - 1; j >= 0; j--, num++)
				A[i][j] = num;
			isToRight = true;
		}
	}
	
	// Output
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cout.width(3);
			cout << A[i][j];
		}
		cout << '\n';
	}
	
	return 0;
}
