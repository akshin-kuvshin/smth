#include <iostream>
using namespace std;

// Constants
const int N_max = 1e2;

// Variables
int N,
	cake[N_max + 5][N_max + 5];

int main() {
	// Input
	cin >> N;
	for (int i = 0; i < N; ++i)
		for (int j = 0; j < N; ++j)
			cin >> cake[i][j];
	
	// Solution + Output
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < N; ++j) {
			if (cake[i][j])
				cout << 0;
			else
				cout << 1;
			cout << ' ';
		}
		cout << '\n';
	}
		
	return 0;
}
